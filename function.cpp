#include<iostream>
#include<string>

#include "split.h"



int func(int name);
void func(std::string name);
int main()
{
    nt a = sum(-1,2);
    std::cout<<a<<std::endl;

    func("nihao");
    func(10);
    return 0;
}
void func(std::string name)
{
    std::cout<<name<<std::endl;
}
int func(int name)
{
    std::cout<<name<<std::endl;
    return 0;
}
