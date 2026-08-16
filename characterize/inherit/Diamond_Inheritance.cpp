#include<iostream>
class Base
{
    public:
        int m_age = 100;
};
class P1:virtual public Base{};
class P2:virtual public Base{};
//利用虚继承解决继承问题
class C:public P1,public P2{};
int main()
{
    C c;
    //c.P2::m_age=28;
    //c.P1::m_age = 30;
    std::cout<<c.P2::m_age<<std::endl;
    std::cout<<c.P1::m_age<<std::endl;
    std::cout<<c.m_age<<std::endl;
    std::cout<<sizeof(c)<<std::endl;
    return 0;
}