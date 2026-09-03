#include<iostream>
template<typename T>//声明一个模版，T不报错
void swit(T &a , T &b)
{
    T c = a;
    a=b;
    b=c;
}
void switInt(int &a , int &b)
{
    int c = a;
    a=b;
    b=c;
}
void switFloat(float &a , float &b)
{
    float c = a;
    a=b;
    b=c;
}
template<class T>
void init(T &a,T &b)
{
    a = 0;
    b = 0;
}
int main()
{
    int a =10;
    int b =20;
    switInt(a,b);
    swit(a,b);
    std::cout<<"a:"<<a<<std::endl;
    std::cout<<"b:"<<b<<std::endl;
    float c =20.1;
    float d =293.01;
    switFloat(c,d);
    swit(c,d);
    swit<float>(c,d);
    std::cout<<"c:"<<c<<std::endl;
    std::cout<<"d:"<<d<<std::endl;

    init(a,b);
    std::cout<<"a:"<<a<<std::endl;
    std::cout<<"b:"<<b<<std::endl;
    init(c,d);
    std::cout<<"c:"<<c<<std::endl;
    std::cout<<"d:"<<d<<std::endl;
    return 0;
}