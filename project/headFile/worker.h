#pragma once
#include<iostream>
#include<string>
class Worker
{
    public:
        std::string name ;
        int id;
        int level;

        virtual void show_info()=0;
        virtual std::string getLevel()=0;

};

