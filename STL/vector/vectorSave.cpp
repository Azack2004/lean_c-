#include<iostream>
#include<vector>

void print(std::vector<int> &v)
{
    for(std::vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;
}
void printf(std::vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
       std::cout<<v[i]<<" "; 
    }
    std::cout<<std::endl;
}
int main()
{
    std::vector<int> v1;
   for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
   printf(v1);
   int n =0;
   int * p =nullptr;
   std::vector<int> v2;
   v2.reserve(22000);
    for(int i=10;i<22000;i++)
    {
        
        v2.push_back(i);
        if(p!=&v2[0])
        {
            p= &v2[0];
            n++;

        }
    }
    std::cout<<n<<std::endl;
    std::cout<<"Capacity:"<<v2.capacity()<<std::endl;
    std::cout<<"Size:"<<v2.size()<<std::endl;
    v2.resize(3,0);
    std::vector<int>(v2).swap(v2);
    std::cout<<"Capacity:"<<v2.capacity()<<std::endl;
    std::cout<<"Size:"<<v2.size()<<std::endl;
    
    return 0;
}