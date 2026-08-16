#include<iostream>
class Calculator
{
    public:
        int m_Num;
        int m_Num2;
        Calculator(int a,int b):m_Num(a),m_Num2(b){}
        virtual int getresult(std::string oper)
        {
            if(oper == "+")
            {
                return m_Num+m_Num2;
            }
            else if(oper == "-")
            {
                return m_Num-m_Num2;
            }
            else if(oper == "*")
            {
                return m_Num*m_Num2;

            }
            else if (oper == "/")
            {
                return m_Num/m_Num2;
            }
            return -1;
        }
};
class add : public Calculator
{
    public:
        add(int a, int b) : Calculator(a, b) {}
        int getresult(std::string oper)
         {
            if(oper == "+")
            {
                return m_Num+m_Num2;
            }
            else if(oper == "-")
            {
                return m_Num-m_Num2;
            }
            else if(oper == "*")
            {
                return m_Num*m_Num2;

            }
            else if (oper == "/")
            {
                return m_Num/m_Num2;
            }
            else if (oper == "%")
            {
                return m_Num%m_Num2;
            }
            return -1;
        }
};

int getresult(Calculator & c,std::string oper)
{
    return  c.getresult(oper);
}

//实现计算器的抽象类
class AbstractCalculator
{
    public:
        int m_Num;
        int m_Num2;
        AbstractCalculator(int a,int b):m_Num(a),m_Num2(b){}
        virtual int  getresult()
        {
            return 0;
        };
};

class AddCalculator : public AbstractCalculator
{
    public:
        AddCalculator(int a,int b):AbstractCalculator(a,b){}
        int getresult()
        {
            return m_Num+m_Num2;
        }
};

class SubCalculator : public AbstractCalculator
{
    public:
        SubCalculator(int a,int b):AbstractCalculator(a,b){}
        int getresult()
        {
            return m_Num-m_Num2;
        }
};

class MulCalculator : public AbstractCalculator
{
    public:
        MulCalculator(int a,int b):AbstractCalculator(a,b){}
        int getresult()
        {
            return m_Num*m_Num2;
        }
};
int getresult(int a,int b)
{   
    AbstractCalculator * c = new AbstractCalculator(a,b);
    return c->getresult();
}
int main()
{
    Calculator c(1,2);
    // std::cout<<c.getresult("+")<<std::endl;
    add a(19,2);
    std::cout<<getresult(a,"%")<<std::endl;
    std::cout<<getresult(c,"%")<<std::endl;
    return 0;
}