#include<iostream>
#include<functional>
//negate取反仿函数
//plus加法仿函数
int main()
{
    std::negate<int> n;
    std::cout<<n(50)<<std::endl;
    std::plus<int> p;
    std::cout<<p(10,20)<<std::endl;
    return 0;
}