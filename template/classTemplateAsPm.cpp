#include<iostream>
template<typename T1,typename T2>
class Person
{

    public:
        Person(const T1 & a,const T2 &b):name(a),age(b){}
        T1 name;
        T2 age;
        void showPerson()
        {
            std::cout<<this->age<<std::endl;
            std::cout<<this->name<<std::endl;
        }
};
//1.指定传入类型
// void show( Person<std::string ,int>& p)
// {
//     p.showPerson();
// }
//2.参数模版化
// template<typename T1,typename T2>
// void show( Person<T1 ,T2>& p)
// {
//     p.showPerson();
//     std::cout<<"T1:"<<typeid(T1).name()<<std::endl;
//     std::cout<<"T1:"<<typeid(T2).name()<<std::endl;
// }
//3.将整个类模版化
template<typename T>
void show(T &a)
{
    a.showPerson();
    std::cout<<"T:"<<typeid(T).name()<<std::endl;
}
int main()
{
    Person<std::string ,int> p("hello",10);
    show(p);
    return 0;
}