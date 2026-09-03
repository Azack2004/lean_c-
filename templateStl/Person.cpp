#include<iostream>
#include"Person.h"
template<typename T1,typename T2>
Person<T1,T2>::Person(const T1 &n, const T2 &a )
{
    this->name = n;
    this->age = a;
}
template<typename T1,typename T2>
void Person<T1,T2>::show()
{
    std::cout<<this->name<<std::endl;
    std::cout<<this->age<<std::endl;
}
template class Person<int ,std::string>;
//显示调用，同时有模版的定义和调用，才能生成具体的函数