#include<iostream>
 
class BasePage
{
    public:
        void header()
        {
            std::cout<<"JAVA header"<<std::endl;
        }
        void footer()
        {
            std::cout<<"JAVA footer"<<std::endl;
        }
};
//继承，减少重复的代码
//
class JAVA :public BasePage
{
    public:
        void content()
        {
            std::cout<<"java"<<std::endl;
        }
};
int main()
{
    JAVA j;
    j.header();
    j.footer();
    return 0;
}