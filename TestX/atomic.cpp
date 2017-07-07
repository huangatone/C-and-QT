//
//  atomic.cpp
//  TestX
//
//  Created by Rong Huang on 7/4/17.
//  Copyright © 2017 Rong Huang. All rights reserved.
//

#include <stdio.h>
#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

std::atomic<int> x(0),y(0),z(0);  // 1
std::atomic<bool> go(false);  // 2
unsigned const loop_count=10;
struct read_values
{
    int x,y,z;



};


read_values values1[loop_count];
read_values values2[loop_count];
read_values values3[loop_count];
read_values values4[loop_count];
read_values values5[loop_count];
void increment(std::atomic<int>* var_to_inc,read_values* values)
{
    
    while(!go)
    std::this_thread::yield(); // 3 自旋，等待信号
    for(unsigned i=0;i<loop_count;++i)
    {
        cout <<"id = " << std::this_thread::get_id() << endl;
        values[i].x=x.load(std:: memory_order_acquire);
        values[i].y=y.load(std:: memory_order_acquire);
        values[i].z=z.load(std:: memory_order_acquire);
        var_to_inc->store(i+1,std::memory_order_acquire);  // 4
        std::this_thread::yield();
        cout <<"id = " << std::this_thread::get_id() << endl;
    }
}

void read_vals(read_values* values)
{
    while(!go)
    std::this_thread::yield(); // 5 自旋，等待信号
    for(unsigned i=0;i<loop_count;++i)
    {
        values[i].x=x.load(std::memory_order_relaxed);
        values[i].y=y.load(std::memory_order_relaxed);
        values[i].z=z.load(std::memory_order_relaxed);
        std::this_thread::yield();
    }
}

void print(read_values* v)
{
    for(unsigned i=0;i<loop_count;++i)
    {
        if(i)
        std::cout<<",";
        std::cout<<"("<<v[i].x<<","<<v[i].y<<","<<v[i].z<<")";
    }
    std::cout<<std::endl;
}
int main()
{
        std::thread t1(increment,&x,values1);
        std::thread t2(increment,&y,values2);
        std::thread t3(increment,&z,values3);

        std::thread t4(read_vals,values4);
        std::thread t5(read_vals,values5);

        go=true; // 6 开始执行主循环的信号
        t5.join();
        t4.join();
        t3.join();
        t2.join();
        t1.join();
        print(values1);
        cout << "---------------------------------------------------";
        print(values2);
        cout << "---------------------------------------------------";
        print(values3);
        cout << "---------------------------------------------------";
        print(values4);
        cout << "---------------------------------------------------";
        print(values5);

        std::atomic_int a;
        a.store(100);
        a.store(10);
        a.fetch_add(105);
        int b = a.load(std::memory_order_relaxed);

        cout <<endl<< "----------------------------------" << endl;
        cout << "b = " <<b;

        b = a.load(std::memory_order_relaxed);

        cout <<endl<< "----------------------------------" << endl;
        cout << "b = " <<b;
        cout <<endl<< "----------------------------------" << endl;
        for(unsigned i=0;i<loop_count;++i)
        {
            if(i)
            std::cout<<",";
            std::cout<<"("<<values1[i].x<<","<<values1[i].y<<","<<values1[i].z<<")";
            std::cout<<"("<<values2[i].x<<","<<values2[i].y<<","<<values2[i].z<<")";
            std::cout<<"("<<values3[i].x<<","<<values3[i].y<<","<<values3[i].z<<")";
             std::cout<<std::endl;
        }
        std::cout<<std::endl;
    
}
