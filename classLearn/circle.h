#pragma once
#include<iostream>
#include"point.h"

class Circle
{
    Point m_center ;
    int m_redius = 0;
    public:
        void setCircle(const Point & center,const int & redius);
        bool ifInside(const Point & p );
};