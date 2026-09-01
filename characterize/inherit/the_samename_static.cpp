#include<iostream>
class Base
{
    public:
        static  int pub ;
        Base()
        {
            pub = 100;//可以这么用
            std::cout<<"BASE构造函数"<<std::endl;
        }
        static void func()
        {
            std::cout<<"Base的func"<<std::endl;
        }
        static void func(int a)
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
int Base::pub = 101;
class Son :public Base
{
    public:
        static int pub ;
        Son()
        {
            std::cout<<"Son构造函数"<<std::endl;
        }
        static void func()
        {
            std::cout<<"Son的func"<<std::endl;
        }
        ~Son()
        {
            std::cout<<"Son析构函数"<<std::endl;
        }
};
int Son::pub = 200;
int main()
{
    Son s;
    std::cout<<s.pub<<std::endl;
    std::cout<<s.Base::pub<<std::endl;
    s.func();
    s.Base::func(100);
    s.Base::func();
    std::cout<<Son::pub<<std::endl;
    std::cout<<Base::pub<<std::endl;
    std::cout<<Son::Base::pub<<std::endl;
    Son::func();
    Base::func();
    Base::func(100);
    return 0;
}