#pragma once
#include<iostream>
class Point
{
    int m_x=0;
    int m_y=0;
    public:
        void setPoint(const int & x,const int & y);
    
        int getX() const;
        int getY() const;
    
};