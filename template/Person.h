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