#include"circle.h"

void Circle::setCircle(const Point & center,const int & redius)
        {
            m_center=center;
            m_redius = redius;
        }
bool Circle::ifInside(const Point & p )
{
    int length = (m_center.getX()-p.getX())*(m_center.getX()-p.getX())+(m_center.getY()-p.getY())*(m_center.getY()-p.getY());
    if(m_redius*m_redius<length)
    {
        std::cout<<"圆外"<<std::endl;
        return false;
    }else if(m_redius*m_redius>length)
    {
        std::cout<<"圆内"<<std::endl;
        return true;
    }else{
        std::cout<<"圆上"<<std::endl;
        return false;
    }
}