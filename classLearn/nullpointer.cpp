#include<iostream>
class Person
{
    public:
        void showClassName()
        {
            std::cout<<"this is Person class."<<std::endl;
        }
        void showAge()
        {   //报错的原因是this为nullptr
            if(this == nullptr)
            {
                return ;
            }
            std::cout<<age<<std::endl;
        }

        int age;
};
int main()
{
    Person * p = nullptr;
    p->showAge();
    p->showClassName();
    return 0;
}