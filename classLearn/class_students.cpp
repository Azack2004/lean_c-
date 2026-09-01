#include<iostream>
#include<string>
class Student
{
    public:
        std::string name = "";
        int num =0;

        void stuInit(const std::string &s = "" ,const int & n = 0)
        {
            name = s;
            num = n;
        }
        void showInfo()
        {
            std::cout<<name<<std::endl;
            std::cout<<num <<std::endl;
        }
};
int main()
{
    //Student u1 = {.name="张三",.num=192037564};
    Student u1;
    u1.stuInit("2b",19283);
    Student u2;
    u1.showInfo();
    u2.showInfo();
    return 0;
}