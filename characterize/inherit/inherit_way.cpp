#include<iostream>
class Base1
{
    public:
        int pub = 0;
        
    protected:
        int pro = 0;
    private:
        int pri = 0;
};

class Publ :public Base1
{   
    public:
        void func()
        {
            pub =10;
            pro = 10;
            

        }
};
class Publ2 :protected Base1
{   
    public:
        void func()
        {
            pub =10;
            pro = 10;
            

        }
};
class Publ3 :private Base1
{   
    public:
        void func()
        {
            pub =10;
            pro = 10;
            

        }
};
int main()
{
    Publ p ;
    std::cout<<p.pub<<std::endl;
    return 0;
}