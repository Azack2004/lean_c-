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
    //print(v1);
      std::vector<int> v2 = v1;
   //print(v2);
    std::vector<int> v3;
    v3.assign(v1.begin(),v1.end()-1);
    print(v3);
      std::vector<int> v4;
      v4.assign(10,100);
      print(v4);
    return 0;
}