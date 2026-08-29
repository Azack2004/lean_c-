#pragma once //防止头文件重复包含
#include<iostream>
#include <limits>
#include"worker.h"
/*
管理类
负责：
1.与用户沟通的菜单界面
2.与职工的增删改查
3.与文件的读写
*/
class WorkManager
{
    public:
        WorkManager();

        void Show_Menu();
        void ExitSystem();
        void AddEmp();
        void ShowEmp();
        ~WorkManager();

        int m_EmpNum;//记录员工数量
        Worker** m_EmpArray;//员工数组指针

};