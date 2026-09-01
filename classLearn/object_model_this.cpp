#include<iostream>
//成员变量和成员函数是分开存储的
class Person
{
    int m_a=0;//属于类的对象上的
    //不占用对象内存大小
    static int b ;//不属于类的对象上的
    public:
        Person(int m_a){
            //this解决变量名冲突
            this->m_a = m_a;
        }
        void show()//不属于类的对象上的
        {
            std::cout<<b<<std::endl;
            std::cout<<m_a<<std::endl;
        }
        Person showNow()
        {
            return *this;
        }
        Person& add_m_a(Person & p)
        {
            this->m_a += p.m_a;
            return *this;
        }
};
int Person::b = 0;
int main()
{
    Person p=19;
    p.show();
    std::cout<<sizeof(p)<<std::endl;//1字节
    Person p2 = p.showNow();
    //链式编程思想
    p2.add_m_a(p).add_m_a(p).add_m_a(p);
    p2.show();
    return 0;
}