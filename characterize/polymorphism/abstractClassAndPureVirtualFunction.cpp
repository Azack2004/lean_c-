#include<iostream>
//纯虚函数和抽象类
class Base
{
    public:
        //纯虚函数
        virtual void func() = 0;
};
class Son:public Base
{
    public:
        void func()
        {
            std::cout<<"hello"<<std::endl;
        }
};
int main()
{
    Son s;
    s.func();
    return 0;
}