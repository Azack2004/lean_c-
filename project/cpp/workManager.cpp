#include "../headFile/workManager.h"

WorkManager::WorkManager()
{

}
void WorkManager::Show_Menu()
{
    std::cout<<"***********"<<std::endl;
    std::cout<<"欢迎使用管理系统"<<std::endl;
    std::cout<<"0.退出管理系统"<<std::endl;
    std::cout<<"1.增加职工信息"<<std::endl;
    std::cout<<"2.显示职工信息"<<std::endl;
    std::cout<<"3.删除离职员工"<<std::endl;
    std::cout<<"4.修改职工信息"<<std::endl;
    std::cout<<"5.查找职工信息"<<std::endl;
    std::cout<<"6.按照编号排序"<<std::endl;
    std::cout<<"7.清空所有文档"<<std::endl;
    std::cout<<"***********"<<std::endl;
}
void WorkManager::ExitSystem()
{
    std::cout<<"欢迎下次使用！"<<std::endl;
    exit(0);//退出程序函数，系统自带
}
WorkManager::~WorkManager()
{

}

