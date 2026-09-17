#include<iostream>
#include<thread>
#include<numeric>
#include<vector>
template <typename Iterator,typename T>
class accumulate_block
{
    public:
        void operator()(Iterator _f,Iterator _l ,T &result)
        {
            result = std::accumulate(_f,_l,result);
        }
};
int main()
{
    std::vector<int> v;
    std::vector<std::thread> vt;
   
    int numt = std::thread::hardware_concurrency();
  
    std::vector<long long> sumv(numt);
    for(int a=0;a<40000000;a++)
    {
        v.push_back(a);
    }
    accumulate_block<std::vector<int>::iterator,long long> add;
    int num = std::distance(v.begin(),v.end());
    int max_acculate = 1000;
    for(int i=0;i<numt;i++)
    {
        // std::thread t(add,v.begin()+i*100000,v.begin()+(i+1)*100000,std::ref(sumv[i]));//显视按照引用传递
        // vt.push_back(std::move(t));//这里是复制
        vt.emplace_back(add,v.begin()+i*(num/numt),v.begin()+(i+1)*(num/numt),std::ref(sumv[i]));//vector内部构造
    }
    for(auto it =vt.begin();it!=vt.end();it++ )
    {
        it->join();
    }
    long long sum = 0;
    sum = std::accumulate(sumv.begin(),sumv.end(),sum);
    std::cout<<sum<<std::endl;
    return 0;
}