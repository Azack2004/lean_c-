#include<iostream>
#include<string>
class Cude
{
    int m_L=0;
    int m_H=0;
    int m_W=0;
    public:
        void setCude(const int & l,const int & h,const int & w)
        {
            m_L=l;
            m_H=h;
            m_W=w;
        }
        int getVolume ()
        {
            return m_H*m_L*m_W;
        }
        int getRound()
        {
            return (m_H+m_L+m_W)*4;
        }
        int getH()
        const{
            return m_H;
        }
        int getW()
        const{
            return m_W;
        }
        int getL()
        const{
            return m_L;
        }

        bool isSame(const Cude &c2)
        {
            if((m_H==c2.getH())&&(m_L==c2.getL())&&(m_W==c2.getW()))
            {
                std::cout<<"相等"<<std::endl;
                return true;
            }else{
                std::cout<<"不相等"<<std::endl; 
                return false;
            }
        }
         
       
};
bool isSame(const Cude & c1,const Cude &c2)
{
    if((c1.getH()==c2.getH())&&(c1.getL()==c2.getL())&&(c1.getW()==c2.getW()))
    {
        std::cout<<"相等"<<std::endl;
        return true;
    }else{
        std::cout<<"不相等"<<std::endl; 
        return false;
    }
}
int main()
{
    Cude c1,c2,c3;
    c1.setCude(100,20,40);
    c2.setCude(100,23,45);
    c3.setCude(100,20,40);
    std::cout<<c1.getVolume()<<std::endl;
    std::cout<<c2.getVolume()<<std::endl;
    isSame(c1,c2);
    c1.isSame(c2);
    c1.isSame(c3);
    return 0;
}