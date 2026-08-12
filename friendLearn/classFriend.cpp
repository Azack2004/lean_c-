#include<iostream>
#include<string>
class Building;
class GoodGay
{
    public:
        GoodGay();
        void  visit();
        Building * building;
};
class Building
{   
    friend class GoodGay;
    public:
        Building();
        std::string m_SitingRoom;
    private:
        std::string m_BedRoom;
};
Building::Building():m_BedRoom("卧室"),m_SitingRoom("客厅"){}
GoodGay:: GoodGay(){
            building =  new Building;
        }
void GoodGay::visit()
        {
            std::cout<<building->m_SitingRoom<<std::endl;
            std::cout<<building->m_BedRoom<<std::endl;
        }
int main()
{
    GoodGay g;
    g.visit();
    return 0;
}