//
//  CodePorject.cpp
//  TestX
//
//  Created by Rong Huang on 6/29/17.
//  Copyright © 2017 Rong Huang. All rights reserved.
//

#include "CodePorject.hpp"

#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <string>
using namespace std;


/*
void func(int& a)
{
    a++;
}

int main()
{
    int a = 42;
    std::thread t(func, std::ref(a));
    t.join();
    
    std::cout << a << std::endl;
    
    return 0;
}*/

std::mutex g_lock;
/*
void func()
{
    g_lock.lock();
    
    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
    
    g_lock.unlock();
}

int main()
{
    srand((unsigned int)time(0));
    
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}*/

/*
 template <typename T>
 class container
 {
 //std::mutex _lock;
 std::recursive_mutex _lock;
 std::vector<T> _elements;
 public:
 void add(T element)
 {
     std::lock_guard<std::recursive_mutex> locker(_lock);
     //_lock.lock();
     _elements.push_back(element);
     //_lock.unlock();
 }
 
 void addrange(int num, ...)
 {
     va_list arguments;
 
     va_start(arguments, num);
 
     for (int i = 0; i < num; i++)
     {
         std::lock_guard<std::recursive_mutex> locker(_lock);
         //_lock.lock();
         add(va_arg(arguments, T));
        // _lock.unlock();
     }
 
     va_end(arguments);
 }
 
 void dump()
 {
     _lock.lock();
     for(auto e : _elements)
         std::cout << e << std::endl;
     _lock.unlock();
 }
 };
 
 void func(container<int>& cont)
 {
     cont.addrange(3, rand(), rand(), rand());
 }
 
 int main()
 {
     srand((unsigned int)time(0));
 
     container<int> cont;
 
     std::thread t1(func, std::ref(cont));
     std::thread t2(func, std::ref(cont));
     std::thread t3(func, std::ref(cont));
 
     t1.join();
     t2.join();
     t3.join();
 
     cont.dump();
 
     return 0;
 }*/

/*
 thread_local int j = 0;
 void foo()
 {
 m.lock();
 j++; // j is now 1, no matter the thread. j is local to this thread.
 m.unlock();
 }
 void func()
 {
 j = 0;
 std::thread t1(foo);
 std::thread t2(foo);
 t1.join();
 t2.join();
 // j still 0. The other "j"s were local to the threads
 }
 */

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <random>

std::mutex              g_lockprint;
std::mutex              g_lockqueue;
std::condition_variable g_queuecheck;
std::queue<int>         g_codes;
bool                    g_done;
bool                    g_notified;

void workerfunc(int id, std::mt19937& generator)
{
    // print a starting message
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[worker " << id << "]\trunning..." << std::endl;
    }
    
    // simulate work
    std::this_thread::sleep_for(std::chrono::seconds(1 + generator() % 5));
    
    // simulate error
    int errorcode = id*100+1;
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout  << "[worker " << id << "]\tan error occurred: " << errorcode << std::endl;
    }
    
    // notify error to be logged
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        g_codes.push(errorcode);
        g_notified = true;
        g_queuecheck.notify_one();
    }
}

void loggerfunc()
{
    // print a starting message
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[logger]\trunning..." << std::endl;
    }
    
    // loop until end is signaled
    while(!g_done)
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        
        while(!g_notified) // used to avoid spurious wakeups
        {
            g_queuecheck.wait(locker);
        }
        
        // if there are error codes in the queue process them
        while(!g_codes.empty())
        {
            std::unique_lock<std::mutex> locker(g_lockprint);
            std::cout << "[logger]\tprocessing error:  " << g_codes.front()  << std::endl;
            g_codes.pop();
        }
        
        g_notified = false;
    }
}

int mainCode()
{
    // initialize a random generator
    std::mt19937 generator((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    
    // start the logger
    std::thread loggerthread(loggerfunc);
    
    // start the working threads
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(workerfunc, i+1, std::ref(generator)));
    }
    
    // work for the workers to finish
    for(auto& t : threads)
        t.join();
    
    // notify the logger to finish and wait for it
    g_done = true;
    loggerthread.join();
    
    return 0;
}
