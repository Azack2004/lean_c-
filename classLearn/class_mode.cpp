#include<iostream>
/*
public
protexted
private
*/
class Person
{
    private:
        std::string name="";
        std::string m_car="";

        int m_password = 0;

    public:
        void func(const std::string & n="",const std::string & car="",const int & password=0)
        {
            name = n;
            m_car = car;
            if(password>0&&password<100)
            {
                 m_password = password;
            }else{
                std::cout<<"输入错误"<<std::endl;
                m_password = 0;
            }
           
        }
        void showinfo()
        {
            std::cout<<name<<std::endl;
            std::cout<<m_car<<std::endl;
            std::cout<<m_password<<std::endl;

        }
};
int main()
{
    Person p1;
    p1.func("nihao","toyuto",192035);
    p1.showinfo();
    return 0;
}