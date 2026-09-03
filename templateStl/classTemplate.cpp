#include<iostream>
#include<string>
template<typename Name=std::string ,typename Age=int>
class Person
{
    
    public:
        Name name;
        Age age;

        Person(Name name,Age age){
        this->age = age;
        this->name = name;
         }
        void showInfo()
        {
            std::cout<<this->name<<std::endl;
            std::cout<<this->age<<std::endl;
        }
};
template<typename T>
class Student
{
    public:
        Student(T & b):a(b){}
        T a;
        void showInfo()
        {
            a.showInfo();
        }
};
int main()
{
    Person<int,int> p1(10,10);
    p1.showInfo();
    Person<int,std::string> p2(10,"hello");
    p2.showInfo();
    Student<Person<int ,int>> s(p1);
    s.showInfo();
    return 0;
}