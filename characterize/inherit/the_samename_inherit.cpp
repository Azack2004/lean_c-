#include<iostream>
class Base
{
    public:
        int pub = 0;
        Base()
        {
            pub = 100;
            std::cout<<"BASE构造函数"<<std::endl;
        }
        void func()
        {
            std::cout<<"Base的func"<<std::endl;
        }
        void func(int a)
        {
            std::cout<<"Base的func:"<<a<<std::endl;
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
        int pub = 20;
        Son()
        {
            std::cout<<"Son构造函数"<<std::endl;
        }
        void func()
        {
            std::cout<<"Son的func"<<std::endl;
        }
        ~Son()
        {
            std::cout<<"Son析构函数"<<std::endl;
        }
};
int main()
{
    Son s;
    std::cout<<s.pub<<std::endl;
    std::cout<<s.Base::pub<<std::endl;
    s.func();
    s.Base::func(100);
    s.Base::func();
    return 0;
}