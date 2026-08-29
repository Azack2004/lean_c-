#include "../headFile/workManager.h"
#include "../headFile/boss.h"
#include "../headFile/manager.h"
#include "../headFile/employee.h"
WorkManager::WorkManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray =nullptr;
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
void WorkManager::AddEmp()
{
    int add_num=0;
    std::cout<<"增加员工数量：";
    std::cin>>add_num;
    if(add_num<0)
    {
        std::cout<<"请输入合法数字。";
        return ;
    }

    //添加逻辑
    int newSize = this->m_EmpNum+add_num;
    //开辟空间
    Worker** newSpace = new Worker*[newSize];//两个Work**指针，一个原来的，一个新增的
    if(this->m_EmpArray!=nullptr)
    {
        for(int i=0;i<this->m_EmpNum;i++)
        {
            newSpace[i]=this->m_EmpArray[i];
        }
        delete this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
    //加入新数据
    for(int i=0;i<add_num;i++)
    {
        int id;
        std::string name;
        int level;
        std::cout<<"输入"<<i+1<<"个要添加的职工"
        <<std::endl<<"姓名:";
        std::cin>>name;
        std::cout<<"id:";
        std::cin>>id;
    

        Worker* w = nullptr;
        bool levelStatus = true;
        while (levelStatus)
        {   std::cout<<std::endl<<"1.老板 "<<"2.经理 "<<"3.员工 "<<std::endl<<"level:";
            std::cin>>level;
            switch (level)
            {
            case 1:
                {
                w = new Boss(name,id,level); 
                levelStatus = false; 
                break;
                }
            case 2:
                {
                w = new Manager(name,id,level); 
                levelStatus = false; 
                break;
                }   
            case 3:
                {
                w = new Employee(name,id,level); 
                levelStatus = false; 
                break;
                }   
            
            default:
                if (std::cin.fail()) {
                std::cin.clear(); // 修复标志位，让 cin 恢复正常工作
                }
                // 清空缓冲区里残留的字符，直到遇到换行符 '\n'
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"输入合法的数字."<<std::endl;
                
                break;
            }
        }
        newSpace[this->m_EmpNum+i]=w;
        
    }
   this->m_EmpArray = newSpace;  
   this->m_EmpNum = newSize;  
}
void WorkManager::ShowEmp()
{
    for(int i=0;i<this->m_EmpNum;i++)
    {
       this->m_EmpArray[i]->show_info();
    }
}
WorkManager::~WorkManager()
{

}

