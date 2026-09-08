#include<iostream>
#include<vector>

void print(std::vector<int> &v)
{
    for(std::vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        std::cout<<(*it)<<std::endl;
    }
}
int main()
{
    std::vector<int> v1;
   for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    v1.insert(v1.begin()+3,11);
    //print(v1);
    v1.pop_back();
   // print(v1);
    v1.insert(v1.begin(),1,101);
    v1.erase(v1.begin());
    v1.clear();
    print(v1);
    return 0;
}