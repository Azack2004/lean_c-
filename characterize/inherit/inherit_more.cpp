#include<iostream>
class Father
{
    public:
        int f_a=0;
        int a =0;
};
class Mother
{
    public:
        int m_a =0;
        int a = 2;
};
class Child: public Father ,public Mother
{
    public:
        int c_a =100;
        int a = 23;
};
int main()
{
    Child c;
    std::cout<<sizeof(c)<<std::endl;
    std::cout<<c.a<<std::endl;
    std::cout<<c.Father::a<<std::endl;
    std::cout<<c.Mother::a<<std::endl;
    return 0;
}