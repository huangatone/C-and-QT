//
//  main.cpp
//  TestX
//
//  Created by Rong Huang on 6/26/17.
//  Copyright © 2017 Rong Huang. All rights reserved.
//



#include <thread>
#include <atomic>
#include <iostream>
using namespace std;


class background_task
{
public:
    void do_something()
    {
        cout << "out print: do something" << endl;
        
    }
    void do_something_else()
    {
        cout << "out print: do else" << endl;
        
    }
    
    void operator()()
    {
        do_something();
        
        do_something_else();
        
    }
};

void do_something()
{
   
}
void do_something_else()
{
    std::this_thread::get_id();
    cout << "out print: do else" << endl;
}

void do_some_work()
{
    std::this_thread::get_id();
    cout << "out print" << endl;
}


void f(int i,std::string const& s)
{
   
}
void oops(int some_param)
{
    char buffer[1024]; // 1
    sprintf(buffer, "%i",some_param);
    std::thread t(f,3,buffer); // 2
    t.detach();
}


int main1(int argc, char *argv[])
{
    auto cpu_num = std::thread::hardware_concurrency() ;
    std::thread my_thread(do_some_work);
    cout << "exit" << endl;
    my_thread.join();
    
    background_task f;
    std::thread my_thread123(f);
    my_thread123.join();
    
    std::thread my_thread224([]{
        do_something();
        do_something_else();
    });
    
    my_thread224.join();
    return 0;
}
