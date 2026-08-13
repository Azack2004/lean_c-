#include<iostream>
class MyInteer
{
    friend std::ostream & operator<<(std::ostream & cout,const MyInteer & a);
    private:
        int key;
        int value;
    public:
        MyInteer(int&& a,const int & b):value(a),key(b){}
        //重载前置++运算符
        MyInteer & operator++()
        {
            ++value;
            ++key;
            return *this;
        }
        //重载后置++递增
        MyInteer  operator++(int)//占位参数，用于区分前置后置
        {
            //先记录当时结果
            MyInteer p = *this;
            //后加一
            ++value;
            ++key;
    
            return p;
        }
};


//重载左移运算符
std::ostream & operator<<(std::ostream & c,const MyInteer & a)
{
    std::cout<<a.value<<" "<<a.key;
    return c;
}
int main()
{
    MyInteer a(100,19);
    std::cout<<++(++a)<<std::endl;
    std::cout<<a<<std::endl;

    std::cout<<a++<<std::endl;
    std::cout<<a<<std::endl;
    
    return 0;
}