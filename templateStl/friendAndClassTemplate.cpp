#include<iostream>
template<typename T1,typename T2>
class Person
{   template<typename U1,typename U2>
    friend void show(const Person<U1,U2> & p);
    private:
        T1 a;
    public:
        T2 b;
        Person(const T1 &m_a,const T2 &m_b):a(m_a),b(m_b){}
        
};
template<typename T1,typename T2>
void show(const Person<T1,T2> & p)
{
    std::cout<<p.a<<p.b<<std::endl;
}
int main()
{
    Person<int,char> p(10,'c');
    show<int,char>(p);
    return 0;
}