#include<iostream>
#define M 100
const int c =100 ;
int * abd();
int main()
{
    int a =10;
    int b = 100;
    const int d =100 ;
    std::cout<<"&a="<<&a<<std::endl;
    std::cout<<"&b="<<&b<<std::endl;
    std::cout<<"&c="<<&c<<std::endl;
    std::cout<<"&d="<<&d<<std::endl;
    /*
    &a=0xfffffc14a4ac
    &b=0xfffffc14a4b0
    &c=0xba2ba9d60bb8
    &d=0xfffffc14a4b4
    */
   //静态变量
    static int  e =100;
    std::cout<<"&e="<<&e<<std::endl;
    //常量 字符串常量，const常量
    //const常量 const修饰的全局变量，const修饰的全局变量
    std::cout<<"字符串常量的地址："<<&"hello world"<<std::endl;
    //堆区
    int * p =abd();
    std::cout<<"&p="<<&p<<std::endl;
    std::cout<<"*p="<<*p<<std::endl;
    std::cout<<"&p="<<&p<<std::endl;
    return 0;
}


int * abd()
{   //new int(100)返回地址
    //指针p是局部变量，放在栈区，p保存的数据是在堆区上
    int*p = new int(100);
    return p;
}