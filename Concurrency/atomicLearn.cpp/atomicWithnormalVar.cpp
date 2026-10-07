#include<iostream>
#include<atomic>
#include<thread>
std::atomic<bool> data_flag{false};
std::atomic<bool> data_flag2{false};
int a = 0;
void thread1()
{
    a = 10;
    data_flag.store(true,std::memory_order_release);
}
void thread2()
{
    while(!data_flag.load(std::memory_order_acquire));
    std::cout<<a+1<<std::endl;
    a = a+10;
    data_flag2.store(true,std::memory_order_release);
}
void thread3()
{
    while(!data_flag2.load(std::memory_order_acquire));
    std::cout<<a+1<<std::endl;

}
int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}