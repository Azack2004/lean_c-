#include<iostream>
#include"headFile/worker.h"//抽象类
#include"headFile/workManager.h"//界面
#include"headFile/boss.h"
#include"headFile/employee.h"
#include"headFile/manager.h"
void show_info(Worker * w)
{
    w->show_info();
}

int main()
{
    WorkManager wm;

    int choice = 0;
    bool run_state = true;
    wm.GetFile();
    while(run_state)
    {
         wm.Show_Menu();
       
        std::cout<<"输入选择：";
        std::cin>>choice;
        switch (choice)
        {
        /*
        std::cout<<"欢迎使用管理系统"<<std::endl;
        std::cout<<"0.退出管理系统"<<std::endl;
        std::cout<<"1.增加职工信息"<<std::endl;
        std::cout<<"2.显示职工信息"<<std::endl;
        std::cout<<"3.删除离职员工"<<std::endl;
        std::cout<<"4.修改职工信息"<<std::endl;
        std::cout<<"5.查找职工信息"<<std::endl;
        std::cout<<"6.按照编号排序"<<std::endl;
        std::cout<<"7.清空所有文档"<<std::endl;
        */
        case 0:
            wm.ExitSystem();   
            break;
        case 1:
            /* code */
            wm.AddEmp();
            wm.Save();
            
            break;
        case 2:
            /* code */
            wm.ShowEmp();
            break;
        case 3:
            wm.DelEmp();
            wm.Save();
            break;
        case 4:
            wm.ModifyEmp();
            wm.Save();
            break;
        case 5:
            {
                int res = wm.FindEmp();
                if(res==-1)
                {
                    std::cout<<"查无此人"<<std::endl;
                }
                else{
                    wm.m_EmpArray[res]->show_info();
                }
                break;
            }
            
        case 6:
            wm.SortEmp();
            wm.Save();
            break;
        case 7:
            wm.ClearEmp();
            wm.Save();
            break;
        default:
            std::cout<<"请输入合法的数字"<<std::endl;
            break;
        }
    }
    
    return 0;
}