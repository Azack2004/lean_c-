#include<atomic>
#include<thread>
#include<iostream>
#include<future>
void print(std::atomic<int> &a)
{
    int b = a.load();
    std::cout<<b<<std::endl;
    a.fetch_add(10);
    std::cout<<a<<std::endl;
}
int excha(std::atomic<int> &a)
{
    int b =  a.exchange(32);
    return b;
}
int main()
{
    std::atomic<int> a(0);
    std::thread t(print,std::ref(a));
    std::thread t1(print,std::ref(a));
    t.join();
    t1.join();
    std::cout<<a<<std::endl;
    std::future<int> f =  std::async(excha,std::ref(a));
    std::cout<<f.get()<<std::endl;
    std::cout<<a<<std::endl;
    return 0;
}