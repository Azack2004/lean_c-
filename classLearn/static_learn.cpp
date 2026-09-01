#include<iostream>
//静态成员变量
class Person
{
    //类内声明，类外初始化
    public:
    //静态成员变量有访问权限
        static int m_A ;
    static int m_B;

    //所有对象共享同一个函数
    //静态成员函数只能访问静态成员变量
        static void init(int a,int b)
        {
            m_A = a;
            m_B = b;
            std::cout<<m_A<<" "<<m_B<<std::endl;
        } 
};

int Person::m_A = 0;
int Person::m_B = 0;
int main()
{
    //静态成员变量不属于某一个成员，所有对象对象共用一份数据
    //有两种访问方式
    //1.对象访问
    
    Person p;
    p.m_A =200;
    Person p1;
    std::cout<<p1.m_A<<std::endl;
    //2.类名访问
    std::cout<<Person::m_A<<std::endl;
    //对象访问
    p.init(10,2);
    //类名访问
    Person::init(1,2);
    return 0;
}