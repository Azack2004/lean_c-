#include<iostream>

class Person
{   
    friend std::ostream & operator<<(std::ostream & cout,const Person & p);
    private:
        int m_a;
        int m_b;
    public:
        Person(int a,int b):m_a(a),m_b(b){}   
       
};
//只能利用全局函数重载左移运算符
std::ostream & operator<<(std::ostream & cout,const Person & p)
    {
        std::cout << p.m_a<<" "<<p.m_b<<std::endl;
        return cout;
    }
int main()
{
    Person p(1,2);
    std::cout<<p<<std::endl;
    return 0;
}