#pragma once
#include<iostream>
#include<string>
#include"worker.h"

class Boss:public Worker
{
    public:
        Boss(std::string name,int id,int level);
        void show_info() override;
        
};