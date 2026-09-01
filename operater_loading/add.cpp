#include<iostream>
class Person
{
    public:
        int m_a;
        int m_b;
        //成员函数重载
        Person operator+(const Person & p)
        {
            Person temp;
            temp.m_a=this->m_a+p.m_a;
            temp.m_b = this->m_b+p.m_b;
            return temp;
        }
        Person operator+(const int & p)
        const{
            Person temp;
            temp.m_a=this->m_a+p;
            temp.m_b = this->m_b+p;
            return temp;
        }
        void showInfo()
        {
            std::cout<<m_a<<std::endl;
            std::cout<<m_b<<std::endl;
        }
};
//全局函数重载
// Person operator+(const Person & p1,const Person & p2)
// const{
//     Person temp;
//     temp.m_a=p1.m_a+p2.m_a;
//     temp.m_b = p1.m_b+p2.m_b;
//     return temp;
// }
int main()
{
    Person p1 = {.m_a=10,.m_b=20};
    Person p2 = {.m_a=20,.m_b=20};
    Person p3 = p1 +p2 + 10;
    p3.showInfo();
    return 0;
}