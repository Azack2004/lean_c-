#include<iostream>
//抽象CPU
class Cpu
{
    protected:
        std::string * name;
    public:
        Cpu(const std::string & s)
        {
            std::cout<<"CPU的构造函数."<<std::endl;
            name = new std::string(s);
        };
        virtual void calcuiate()=0;
        virtual std::string showCpu()
        {
            //std::cout<<*name<<std::endl;
            return *name;
        }
        virtual ~Cpu() = 0;
};
class Gpu
{
    protected:
        std::string * name;
    public:
        Gpu(const std::string & s)
        {
            std::cout<<"GPU的构造函数."<<std::endl;
            name = new std::string(s);
        };
        virtual void draw()=0;
        virtual std::string showGpu()
         {
            //std::cout<<*name<<std::endl;
            return *name;
        }
        virtual ~Gpu() = 0;
};
class Memory
{
    protected:
        std::string * name;
    public:
        Memory(const std::string & s)
        {
            std::cout<<"Memory的构造函数."<<std::endl;
            name = new std::string(s);
        };
        virtual void remember()=0;
        virtual std::string showMemory()
        {
            //std::cout<<*name<<std::endl;
            return *name;
        }
        virtual ~Memory() = 0;

};
Cpu::~Cpu()
{
    
    if(name!=nullptr)
    {
        delete name;
        name = nullptr;
    }
    std::cout<<"CPU的析构函数."<<std::endl;
}
Gpu::~Gpu()
{
    if(name!=nullptr)
    {
        delete name;
        name = nullptr;
    }
    std::cout<<"GPU的析构函数."<<std::endl;
}
Memory::~Memory(){
    if(name!=nullptr)
    {
        delete name;
        name = nullptr;
    }
    std::cout<<"Memory的析构函数."<<std::endl;
}
class Computer:public Cpu,public Gpu,public Memory
{
    protected:
        std::string * m_name ;
    public:
        Computer(const std::string & c_name,
            const std::string & cpu,
            const std::string & gpu,
            const std::string & memory):Cpu(cpu),Gpu(gpu),Memory(memory)
        {
            std::cout<<"Computer的构造函数."<<std::endl;
            m_name = new std::string(c_name);
        };
        void calcuiate(){
            std::cout<<*m_name<<"Cpu计算"<<std::endl;
        }
        void draw()
        {
            std::cout<<*m_name<<"Gpu绘画"<<std::endl;
        }
        void remember()
        {
            std::cout<<*m_name<<"Memory记忆"<<std::endl; 
        }
        void showname()
        {
            std::cout<<*m_name<<std::endl;
        }
        ~Computer()
        {
            if(m_name!=nullptr)
            {
                delete m_name;
                m_name = nullptr;
            }
            std::cout<<"Computer的析构函数."<<std::endl;
        }
};

void showAll(Computer & co,Cpu & c,Gpu &g,Memory & m)
{
    std::cout<<"----"<<std::endl;
    co.showname();
    c.calcuiate();
    g.draw();
    m.remember();
    std::cout<<"CPU:"<<c.showCpu()<<std::endl;
    std::cout<<"GPU:"<<g.showGpu()<<std::endl;
    std::cout<<"Memory:"<<m.showMemory()<<std::endl;
    std::cout<<"----"<<std::endl;
}
int main()
{
    Computer i("mac","intel","nvidea","sumsung");
    showAll(i,i,i,i);
    return 0;
}