#include<iostream>
#include<memory>
#include<fstream>
int main()
{

    auto fileclose = [](std::ofstream *ofs){
        if(ofs)
        {
            if(ofs->is_open())
            {
                (*ofs).close();
            }
            std::cout<<"delete"<<std::endl;
            delete ofs;
        }
    };
    std::unique_ptr<std::ofstream,decltype(fileclose)> fpr(new std::ofstream("test.txt",std::ios::out),fileclose);
    if(fpr)
    {
        if((fpr->is_open()))
        {
            (*fpr)<<"hello";
        }
    }

    return 0;
}