#include<iostream>
#include<algorithm>
#include<vector>
void print(int v)
{
    std::cout<<v<<std::endl;
}
class printc
{
    public:
        void operator()(int v)
        {
            std::cout<<v<<std::endl;
        }
};
int main()
{
    std::vector<int> v;
    for(int i =0;i<10;i++)
    {v.push_back(i);}
    std::for_each(v.begin(),v.end(),print);
    //std::for_each(v.begin(),v.end(),printc());
    //std::for_each(v.begin(),v.end(),[](int v1)->bool{return v1>7;});
    std::vector<int> v2;
    v2.resize(v.size());
    std::transform(v.begin(),v.end(),v2.begin(),[](int& v)->int{
        if(v>5)
        {
            
            return v;  
        }
        return 0;
    });
    std::for_each(v2.begin(),v2.end(),[](int& v){
        std::cout<<v<<" ";
    });
    std::for_each(v.begin(),v.end(),[](int &v){
        if(v>7)
        {
            v=v*2;
        }
    });
    for(auto it = v.begin();it!=v.end();it++)
    {
       std::cout<<*it<<" "; 
    }
    std::cout<<std::endl;
    auto it =  std::find(v.begin(),v.end(),18);
    if(it!=v.end())
    {
        std::cout<<*it<<std::endl;
    }
    return 0;
}