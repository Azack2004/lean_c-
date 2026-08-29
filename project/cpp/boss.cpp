#include "../headFile/boss.h"
Boss::Boss(std::string name,int id,int level)
{
    this->name=name;
    this->id=id;
    this->level=level;
}
void Boss::show_info()
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
std::string Boss::getLevel()
        {
            return "老板";
        }