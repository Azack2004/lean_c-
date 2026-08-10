#include<iostream>
#include"point.h"
#include"circle.h"

int main()
{
    
    Point p1,p2,p3;
    p1.setPoint(0,0);
    Circle c1;
    c1.setCircle(p1,5);
    p2.setPoint(3,4);
    p3.setPoint(6,7);
    std::cout<<c1.ifInside(p1)<<std::endl;
    std::cout<<c1.ifInside(p2)<<std::endl;
    std::cout<<c1.ifInside(p3)<<std::endl;
    
    return 0;
}