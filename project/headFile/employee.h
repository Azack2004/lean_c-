#pragma once
#include"worker.h"
class Employee :public Worker
{
    public:
        Employee(std::string name,int id,int level);
        void show_info() override;
       
};