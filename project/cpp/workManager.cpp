
#include "../headFile/workManager.h"
#include "../headFile/boss.h"
#include "../headFile/manager.h"
#include "../headFile/employee.h"
WorkManager::WorkManager()
{
    
    this->m_EmpNum = 0;
    this->m_EmpArray =nullptr;
}
void WorkManager::GetStatus()
{
    std::cout<<"m_EmpNum"<<this->m_EmpNum<<std::endl;
}
WorkManager::~WorkManager()
{
  if (this->m_EmpArray != nullptr)
    {
        for (int i = 0; i < this->m_EmpNum; i++)

        {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = nullptr;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
    this->m_EmpNum = 0;
}
void WorkManager::ShowEmp()
{   
    if(this->m_EmpNum!=0)
    {
    for(int i=0;i<this->m_EmpNum;i++)
        {
        this->m_EmpArray[i]->show_info();
        }
    }
    else{
        std::cout<<"无职工"<<std::endl;
    }
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
    bool add_numStatus = true;
    while(add_numStatus)
    {   
        if(add_num>0)
        {
            add_numStatus=false;
        } 
        else {
            if (std::cin.fail()) {
                std::cin.clear(); // 修复标志位，让 cin 恢复正常工作
                }
                // 清空缓冲区里残留的字符，直到遇到换行符 '\n'
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"输入合法的数字."<<std::endl;
            std::cout<<"增加员工数量：";
            std::cin>>add_num;
        } 
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
        delete[] this->m_EmpArray;//释放原有空间
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
        {   std::cout<<"1.老板 "<<"2.经理 "<<"3.员工 "<<std::endl<<"level:";
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
   std::cout<<"添加成功。"<<std::endl;  
}
void WorkManager::Save()
{
    
    std::ofstream ofs;
    ofs.open(FileName,std::ios::out);
    
    for(int i = 0;i<this->m_EmpNum;i++)
    {
       
        ofs<<this->m_EmpArray[i]->name<<"*"
        <<this->m_EmpArray[i]->id<<"%"
        <<this->m_EmpArray[i]->level<<'\n';
    }
    std::cout<<"写入完成."<<std::endl;
    ofs.close();
}
void WorkManager::GetFile()
{
    std::ifstream ifs;
    ifs.open(FileName, std::ios::in);
    std::string b;
    int g=0;
    int count = 0;//文件有多少行
    if (!ifs.is_open())
    {
        std::cout << "文件打开失败，请重试。" << std::endl;
        return;
    }
    while (ifs >> b)
    {
        count++;
    }
     // 文件为空
    if (count == 0)
    {
        ifs.close();

        this->m_EmpNum = 0;

        this->m_EmpArray = nullptr;

        return;
    }
    //回到文件开头
    ifs.clear();
    ifs.seekg(0, std::ios::beg);    
    this->m_EmpArray = new Worker*[count];
    while (ifs >> b)
    {
        int id = 0;
        int level = 0;
        
        // 找 *
        size_t pos1 = b.find('*');

        // 找 %
        size_t pos2 = b.find('%');

        // 获取名字
        std::string name = b.substr(0, pos1);

        // 获取 id
        id = b[pos1 + 1] - '0';

        // 获取 level
        level = b[pos2 + 1] - '0';
        if(level == 1)
        
            m_EmpArray[g] = new Boss(name,id,level);

        if(level == 2)
            m_EmpArray[g] = new Manager(name,id,level);

        if(level == 3)
            m_EmpArray[g] = new Employee(name,id,level);

        g++;
    }

    this->m_EmpNum = count;

    ifs.close();
}
void WorkManager::DelEmp()
{ 
    int id = this->FindEmp();
    if(id==-1)
    {
        return ;
    }
    if(this->m_EmpNum==1)
    {
        if (this->m_EmpArray != nullptr)
        {
            delete this->m_EmpArray[0];
            this->m_EmpArray[0] = nullptr;
        }
        this->m_EmpNum = 0;
    }
    else if(id==this->m_EmpNum){
        this->m_EmpNum -=1;
    }
    else{
        this->m_EmpNum-=1;
        for(int i = id;i<this->m_EmpNum;i++)
        {
            this->m_EmpArray[i] =this->m_EmpArray[i+1]; 
        }
        delete this->m_EmpArray[this->m_EmpNum+1];
        this->m_EmpArray[this->m_EmpNum+1]=nullptr;
    }

    
}
int WorkManager::FindEmp()
{
    int findId = 0;
    std::cout<<"输入id:";
    std::cin>>findId;
    for(int i=0 ;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->id==findId)
        {
            return i;
        }
    }
    return -1;
}
void WorkManager::ModifyEmp()
{
    int id = this->FindEmp();
    if(id==-1)
    {
        return ;
    }

    Worker* w = nullptr;
    std::string name;
    int mid;
    int level;
    std::cout<<"姓名：";
    std::cin>>name;
    std::cout<<"id:";
    std::cin>>mid;
    bool levelStatus = true;
    while (levelStatus)
    {   std::cout<<"1.老板 "<<"2.经理 "<<"3.员工 "<<std::endl<<"level:";
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
    std::cout<<"已修改"<<std::endl;  
    this->m_EmpArray[id]=w;
    this->m_EmpArray[id]->show_info();
}
void WorkManager::SortEmp()
{
    Worker* w = nullptr;
    for(int i=0;i<this->m_EmpNum;i++)
    {   
        for(int j=0;j<this->m_EmpNum-i-1;j++)
        {
            if(this->m_EmpArray[j]->id>this->m_EmpArray[j+1]->id)
            {
                w = this->m_EmpArray[j];
                this->m_EmpArray[j]=this->m_EmpArray[j+1];
                this->m_EmpArray[j+1]=w;
            }
        }
       
    }
    this->ShowEmp();
}
void WorkManager::ClearEmp()
{
    if(this->m_EmpArray!=nullptr)
    {
        for(int i=0;i<this->m_EmpNum;i++)
        {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i]=nullptr;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray=nullptr;
    }
    this->m_EmpNum=0;
}
