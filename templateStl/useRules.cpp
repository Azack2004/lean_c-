#include<iostream>
int add(int a,int b)
{
    std::cout<<"普通函数"<<std::endl;
    return a+b;
}
template<class T>
T add(T a,T b)
{
    std::cout<<"模版函数"<<std::endl;
    return a+b;
}
template<class T>
T add(T a,T b,T c)
{
    std::cout<<"3模版函数"<<std::endl;
    return a+b;
}
int main()
{
    int a =10;
    int b =32;
    //通过同模版参数列表
    add<>(a,b);
    add(10,b,a);
    char c = 'c';
    char d = 'd';
    add(c,d);
    return 0;
}