#include<iostream>
#include<string>
class Building
{   //可以访问私有成员
    friend void goodGay(Building & b);//可以访问私有成员
    public:
        Building():m_BedRoom("卧室"),m_SitingRoom("客厅"){}
        std::string m_SitingRoom;
    private:
        std::string m_BedRoom;
};

void goodGay(Building & b)
{
    std::cout<<b.m_SitingRoom<<std::endl;
    std::cout<<b.m_BedRoom<<std::endl;
}
int main()
{
    Building b;
    goodGay(b);
    return 0;
}