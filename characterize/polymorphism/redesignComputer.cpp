#include<iostream>
// 1. 抽象 CPU 接口
class Cpu {
public:
    virtual void calculate() = 0;
};

// 2. 两个具体的 CPU 子类（实现多态）
class IntelCpu : public Cpu {
public:
    void calculate() override { std::cout << "Intel CPU 高效计算中..." << std::endl; }
};

class AmdCpu : public Cpu {
public:
    void calculate() override { std::cout << "AMD CPU 多核计算中..." << std::endl; }
};
//2.抽象Gpu接口
class Gpu {
public:
    virtual void draw() = 0;
}; 
class IntelGpu : public Gpu {
public:
    void draw() override { std::cout << "Intel GPU 高效绘画中..." << std::endl; }
};

class AmdGpu : public Gpu {
public:
    void draw() override { std::cout << "AMD CPU 多核绘画中..." << std::endl; }
};
//3.抽象Memory接口
class Memory {
public:
    virtual void remember() = 0;
}; 
class IntelMemory : public Memory {
public:
    void remember() override { std::cout << "Intel Memory 高效记忆中..." << std::endl; }
};

class AmdMemory : public Memory {
public:
    void remember() override { std::cout << "AMD Memory 多核记忆中..." << std::endl; }
};
class Computer
{
    private:
        Cpu * c;
        Gpu * g;
        Memory * m;
    public:
        Computer(Cpu&cpu,Gpu&gpu,Memory&mem):c(&cpu),g(&gpu),m(&mem){}
        void work()
        {
            c->calculate();
            g->draw();
            m->remember();
        }
};
int main()
{
    IntelCpu ic;
    AmdCpu ac;
    IntelGpu ig;
    AmdGpu ag;
    IntelMemory im;
    AmdMemory am;
    Computer c1(ic,ag,am);
    c1.work();
    std::cout<<"---"<<std::endl;
    Computer c2(ac,ig,im);
    c2.work();
    return 0;
}