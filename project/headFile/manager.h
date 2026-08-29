#include<iostream>
#include<string>
#include"worker.h"
class Manager:public Worker
{
    public:
        Manager(std::string name,int id,int level);
        void show_info() override;
        std::string getLevel()override ;
};