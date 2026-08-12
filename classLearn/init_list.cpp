#include<iostream>
class Person
{
   
    public:
        int m_a;
        int m_b;
        int m_c;

    // //传统初始化
    // Person(int a,int b,int c){
    //     m_a = a;
    //     m_b = b;
    //     m_c = c;
    // }
    //初始化列表
    Person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
    {

    }
};
int main()
{
    Person a(12,34,5);
    std::cout<<a.m_a<<std::endl;
    return 0;
}