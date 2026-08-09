#include<iostream>
#include<string>
int func(int name);
void func(std::string name);
int main()
{
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