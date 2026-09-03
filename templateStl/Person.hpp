#pragma once
#include<iostream>
template<typename T1 = int,typename T2 = char>
class Person
{
    public:
        T1 name;
        T2 age;
        Person(const T1 &n = 10, const T2 &a = 'c');
        void show();

};
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