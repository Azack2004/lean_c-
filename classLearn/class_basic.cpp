#include<iostream>
#include<string>
#define PI 3.1415

class Round
{   
    //访问权限
    public:
        //属性
        int radius ;

        //行为/方法
        double circumference()
        {
            return 2*PI*radius;
        }
};
int main()
{
    Round c1 = {.radius =200};
    //c1.radius =100;
    std::cout<<c1.circumference()<<std::endl;
    return 0;
}