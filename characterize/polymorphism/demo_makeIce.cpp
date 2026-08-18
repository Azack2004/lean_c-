#include<iostream>
class BaseMake
{
    public:
        std::string water;
        std::string cup;
        std::string tea;
        std::string more ;

        virtual void makewater(std::string water)=0;
        virtual void Usewater(std::string water,std::string tea )=0;
        virtual void Addwater(std::string cup )=0;
        virtual void Addmore(std::string more) = 0;
        virtual void finish(std::string name)=0;

};
class tea:public BaseMake
{
    public:
        void makewater(std::string water)
        {
            std::cout<<"煮"<<water<<"中。。。"<<std::endl;
        }
        void Usewater(std::string water,std::string tea )
        {
            std::cout<<"用"<<water<<"冲"<<tea<<"中。。。"<<std::endl;
        }
        void Addwater(std::string cup )
        {
            std::cout<<"倒入"<<cup<<"中。。"<<std::endl;
        }
        void  Addmore(std::string more)
        {
            std::cout<<"加入"<<more<<"中。。"<<std::endl;
        }
        void finish(std::string name)
        {
            std::cout<<"tea"<<name<<"完成!"<<std::endl;
        }
};

class coffee:public BaseMake
{
    public:
        void makewater(std::string water)
        {
            std::cout<<"煮"<<water<<"中。。。"<<std::endl;
        }
        void Usewater(std::string water,std::string tea )
        {
            std::cout<<"用"<<water<<"冲"<<tea<<"中。。。"<<std::endl;
        }
        void Addwater(std::string cup )
        {
            std::cout<<"倒入"<<cup<<"中。。"<<std::endl;
        }
        void  Addmore(std::string more)
        {
            std::cout<<"加入"<<more<<"中。。"<<std::endl;
        }
        void finish(std::string name)
        {
            std::cout<<"coffee"<<name<<"完成!"<<std::endl;
        }
};
void getmilk(BaseMake & a,std::string water,std::string tea,std::string cup,std::string more,std::string name)
{
    a.makewater(water);
    a.Usewater(water,tea);
    a.Addwater(cup);
    a.Addmore(more);
    a.finish(name);
}
int main()
{
    tea t;
    coffee c;
    getmilk(t,"水","龙井","老茶杯","两只蛤蟆","龙井茶");
    getmilk(c,"矿泉水","咖啡粉","纸杯","柠檬","柠檬咖啡");
    return 0;
}