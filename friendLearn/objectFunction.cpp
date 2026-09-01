#include<iostream>
#include<string>
class Building;
class GoodGay;
class GoodGay
{
    public:
        GoodGay();
        void visit();//访问私有成员
        void visit2();//访问不了私有成员
        Building * building;
};
class Building
{
    friend void GoodGay::visit();
    public:
        Building();
        std::string m_SitingRoom;
    private:
        std::string m_BedRoom;
};
GoodGay::GoodGay()
{
    building = new Building;
}
Building::Building():m_BedRoom("卧室"),m_SitingRoom("客厅"){}
void GoodGay::visit()
{
    std::cout<<building->m_SitingRoom<<std::endl;
    std::cout<<building->m_BedRoom<<std::endl;
}
void GoodGay::visit2()
{
    std::cout<<building->m_SitingRoom<<std::endl;
}

int main()
{
    Building b;
    GoodGay g;
    g.visit();
    g.visit2();
    return 0;
}