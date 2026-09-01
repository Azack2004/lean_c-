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
class t1 : public Base1
{
    public:
        int a =0;
};
int main()
{
    t1 t;
    Base1 b;
    std::cout<<sizeof(t)<<std::endl;
    std::cout<<sizeof(b)<<std::endl;
    return 0;
}