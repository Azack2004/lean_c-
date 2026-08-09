#include<iostream>
int sum(int a=0,int b=0,int c=0);
void func(int =1);
int main()
{
    std::cout<<sum(1,2)<<std::endl;
    func();
    return 0;
}
int sum(int a,int b,int c)
{
    return a+b+c;
}
void func(int)
{
    std::cout<<sum(1,2)<<std::endl;;
}