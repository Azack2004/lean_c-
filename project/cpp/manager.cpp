#include "../headFile/manager.h"
Manager::Manager(std::string name,int id,int level)
{
    this->name=name;
    this->id=id;
    this->level=level;
}
void Manager::show_info()
{
            std::cout<<"姓名:"
            <<name
            <<" "
            <<"id:"
            <<id
            <<" "
            <<"level:"
            <<level
            <<std::endl;
}
std::string Manager::getLevel()
        {
            return "经理";
        }