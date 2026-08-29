#pragma once //防止头文件重复包含
#include<iostream>
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

        ~WorkManager();

};