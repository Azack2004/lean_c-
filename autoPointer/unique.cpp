#include<iostream>
#include<memory>
class Resource
{
    public:
        int name;
        std::string path;
        Resource(){
            std::cout<<"Resource Created"<<std::endl;
        }
        Resource(int n,std::string p):name(n),path(p){
            std::cout<<"Resource Created"<<std::endl;
        }
        ~Resource(){
            std::cout<<"Resource Destroyed"<<std::endl;
        }
        std::unique_ptr<Resource> createResource(int a,const std::string&s)
        {
            std::unique_ptr<Resource> upr(new Resource(a,s));
            std::cout<<"upr地址:"<<&upr<<std::endl;
            return upr;
        }
        void processResource(std::unique_ptr<Resource> upr)
        {
            
            std::cout<<"name:"<<upr->name<<" "<<"path:"<<upr->path<<std::endl;
            std::cout<<"Processing~"<<std::endl;
        }
};
int main()
{
    Resource r;
    auto p = r.createResource(10,"path");
    std::cout<<"p地址:"<<&p<<std::endl;
    r.processResource(std::move(p));//右值触发移动构造

    return 0;
}