#include<iostream>
//常函数，常对象
class Person
{
    public:
        void showPerson()
        const{
            //m_A = 100;
            this->m_B = 100;
        }

        int m_A;
        mutable int m_B;
};
int main()
{
   const Person p={.m_A=10,.m_B=10} ;
   //p.m_A=100;
   p.m_B=102;
   p.showPerson();
    return 0;
}