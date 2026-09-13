#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<random>
#include<numeric>
#include<set>
class Person
{
    public:
        int age;
        std::string name;
        Person(){};
        Person(int a,std::string n):age(a),name(n){};
        bool operator==(const Person &p) const
        {
            if(this->age==p.age&&this->name==p.name)
            {
                return true;
            }
            return false;
        }
        bool operator<(const Person &p) const
        {
            if(this->age<p.age)
            {
                return true;
            }
            return false;
        }
};
template <typename T>
void addVector(T& v,int i )
{
    for(int a =0;a<i;a++)
    {
        v.push_back(a);
    }
}
void addSet(std::set<int>& s,int i )
{
    for(int a =0;a<i;a++)
    {
        s.insert(a);
    }
}
int main()
{  
    std::deque<Person> dq;
    for(int i =0;i<7;i++)
    {
        Person p(i," - ");
        dq.push_front(p);
    }
    Person p(0," - ");
    // dq.push_front(p);
    auto it = std::find_if(dq.begin(),dq.end(),[](const Person& p){return p.age==5;});
    if(it!=dq.end())
    {
        std::cout<<(*it).age<<(*it).name<<std::endl;
    }
    it = std::adjacent_find(dq.begin(),dq.end());
    if(it!=dq.end())
    {
        std::cout<<(*it).age<<(*it).name<<std::endl;
    }
    //改为升序。
    std::sort(dq.begin(),dq.end(),[](const Person&p1,const Person&p2){return p1.age<p2.age;});
    std::cout<<std::binary_search(dq.begin(),dq.end(),p)<<std::endl;
    std::cout<<std::count(dq.begin(),dq.end(),p)<<std::endl;
    std::cout<<std::count_if(dq.begin(),dq.end(),[](const Person&p){return p.age>2;})<<std::endl;
    // 2. 创建随机数生成器 (例如 Mersenne Twister 算法)
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dq.begin(),dq.end(),g);
    std::for_each(dq.begin(),dq.end(),[](const Person&p){std::cout<<p.age<<" ";});
    std::vector<int> v1;
    std::vector<int> v2;
    addVector(v1,8);
    addVector(v2,9);
    std::vector<int> v3;
    //提前给容器分配空间
    v3.resize(v1.size()+v2.size());
    
    std::cout<<std::endl;
    std::for_each(v1.begin(),v1.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    std::for_each(v2.begin(),v2.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
     auto c= v3.begin();
    int count=0;
    std::merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    if(c!=v3.begin())
    {
        count++;
    }
    std::cout<<"count:"<<count<<std::endl;
    std::for_each(v3.begin(),v3.end(),[](const int& a){std::cout<<a<<" ";});
    std::reverse(v3.begin(),v3.end());
    std::cout<<std::endl;
    std::for_each(v3.begin(),v3.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    std::vector<int> v4;
    v4.resize(v3.size());
    std::copy(v3.begin(),v3.end(),v4.begin());
    std::for_each(v4.begin(),v4.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
   //std::replace(v4.begin(),v4.end(),0,101);
    std::for_each(v4.begin(),v4.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    // std::replace_if(v4.begin(),v4.end(),[](int a){
    //     if(a<100)
    //     {
    //         return 1;
    //     }
    //     return 0;
    // },1010);
    std::for_each(v4.begin(),v4.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    std::swap(v1,v4);
    std::for_each(v4.begin(),v4.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    int sum= std::accumulate(dq.begin(),dq.end(),0,[](int sum,const Person&p){return sum+p.age;});
    std::for_each(dq.begin(),dq.end(),[](const Person&p){
        std::cout<<p.age<<" ";
    });
    std::cout<<std::endl;
    std::cout<<"sum:"<<sum<<std::endl;
    std::fill(v4.begin(),v4.end(),100);
    std::for_each(v4.begin(),v4.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    std::set<int> s1;
    std::set<int> s2;
    std::set<int> s3;
    addSet(s1,10);
    addSet(s2,9);

    // std::set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s3,s3.begin()));
    // std::for_each(s3.begin(),s3.end(),[](const int&a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    // std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s3,s3.begin()));
    // std::for_each(s3.begin(),s3.end(),[](const int&a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    std::cout<<"union:";
    std::set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s3,s3.begin()));
    std::for_each(s3.begin(),s3.end(),[](const int&a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    s3.clear();
    std::cout<<"intersection:";
    std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s3,s3.begin()));
    std::for_each(s3.begin(),s3.end(),[](const int&a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    s3.clear();
    std::cout<<"difference:";
    std::set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),std::inserter(s3,s3.begin()));
    std::for_each(s3.begin(),s3.end(),[](const int&a){std::cout<<a<<" ";});
    std::cout<<std::endl;
    // std::cout<<"v1:"<<" ";
    // std::for_each(v1.begin(),v1.end(),[](int a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    // std::cout<<"v2:"<<" ";
    // std::for_each(v2.begin(),v2.end(),[](int a){std::cout<<a<<" ";});
    // std::cout<<std::endl;

    // std::vector<int> v5;
    
    // std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v5,v5.begin()));
    // std::for_each(v5.begin(),v5.end(),[](int a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    // std::set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v5,v5.begin()));
    // std::for_each(v5.begin(),v5.end(),[](int a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    // std::set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v5,v5.begin()));
    // std::for_each(v5.begin(),v5.end(),[](int a){std::cout<<a<<" ";});
    // std::cout<<std::endl;
    return 0;
}