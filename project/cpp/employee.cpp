#include"../headFile/worker.h"
#include"../headFile/employee.h"
Employee::Employee(std::string name,int id,int level)
        {
            this->name = name;
            this->id = id;
            this->level=level;
        }
void Employee::show_info()
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
std::string Employee::getLevel()
        {
            return "员工";
        }