#include<iostream>
#include<thread>
template <typename T>
void func(T&& a)
{
    std::cout<<a<<std::endl;
}
int main()
{
    std::thread t(func<int> ,std::move(10));
    t.join();
    return 0;
}