#include<iostream>
#include<memory>
class NodeB;
class NodeA
{
    public:
        std::weak_ptr<NodeB> pb;
        NodeA(){
            std::cout<<"NodeA Created"<<std::endl;
        }
        ~NodeA()
        {
            std::cout<<"NodeA Destoryed"<<std::endl;
        }
};
class NodeB
{
     public:
        std::weak_ptr<NodeA> pa;
        NodeB(){
            std::cout<<"NodeB Created"<<std::endl;
        }
        ~NodeB()
        {
            std::cout<<"NodeB Destoryed"<<std::endl;
        }
};
int main()
{
    std::shared_ptr<NodeA> pa =  std::make_shared<NodeA>();
    std::shared_ptr<NodeB> pb =  std::make_shared<NodeB>();
    pa->pb = pb;
    pb->pa = pa;
    return 0;
}