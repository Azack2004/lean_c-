#include<iostream>
class Base
{
    public:
        int pub = 0;
        Base()
        {
            std::cout<<"BASE构造函数"<<std::endl;
        }
        ~Base()
        {
            std::cout<<"BASE析构函数"<<std::endl;
        }
    protected:
        int pro = 0;
    private:
        int pri = 0;
};
class Son :public Base
{
    public:
     
        Son()
        {
            std::cout<<"Son构造函数"<<std::endl;
        }
        ~Son()
        {
            std::cout<<"Son析构函数"<<std::endl;
        }
};
int main()
{
    //Base b;
    Son s;
    return 0;
}