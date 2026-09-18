#include<iostream>
#include<thread>
template <typename T>
void func(T& a)
{
    a++;
    std::cout<<a<<std::endl;
}
int main()
{
    int a =10;
    std::thread t(&func<int> ,std::ref(a));//默认拷贝传参
    std::cout<< a<<std::endl;
    t.join();
    return 0;
}