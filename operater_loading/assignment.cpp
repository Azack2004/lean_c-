#include<iostream>
class Person
{
    public:
        Person(int&& a)
        {
            age = new int(a);
        }
        ~Person()
        {
            if(age!=nullptr)
            {
                delete age;
                age = nullptr;
            }
        }
        Person & operator=(Person & p)
        {   
            //应该先判断是否有属性在堆区，有要先释放干净
            if(this->age != nullptr)
            {
                delete this->age;

            }
            this->age = new int (*p.age);
            return *this;
            
        }
    int * age ;
};
int main()
{   Person p1(20);
    Person p2(19);
    Person p3(29);
    std::cout<<*p1.age<<std::endl;
    std::cout<<*p2.age<<std::endl;
    p1 = p2 = p3;
    std::cout<<*p1.age<<std::endl;
    std::cout<<*p2.age<<std::endl;
    std::cout<<*p3.age<<std::endl;
    return 0;
}