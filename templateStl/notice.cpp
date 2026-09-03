#include<iostream>

template <typename T>

T addT(T a,T b)
{
    return a+b;
}
int add(int a,int b)
{
    return a+b;
}
int main()
{
    int a=10;
    int b=25;
    char c = 'd';

    std::cout<< add(a,c)<<std::endl;
    std::cout<< addT<int>(a,c)<<std::endl;
    return 0;
}