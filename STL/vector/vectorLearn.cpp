#include<iostream>
#include<vector>
#include<algorithm>
void print(int a)//写的是对应模版的数据类型
    {
        std::cout<<a<<std::endl;
    }
int main()
{
    std::vector<int> v;
    v.push_back(10);//尾插数据
    v.push_back(11);
    v.push_back(111);
    //通过迭代器访问容器数据
    // std::vector<int>::iterator itBegin = v.begin();//v.begin起始迭代器,指向容器中第一个元素的位置
    // std::vector<int>::iterator itEnd = v.end();//v.end结束迭代器，指向容器中最后一个元素的下一个位置
    // //第一种遍历
    // while(itBegin!=itEnd)
    // {
    //     std::cout<<*itBegin<<std::endl;
    //     itBegin++;
    // }
    //第二种遍历方式
    // for(std::vector<int>::iterator it =v.begin();it!=v.end();it++)
    // {
    //    std::cout<<*it<<std::endl; 
    // }
    //第三种遍历
    std::for_each(v.begin(),v.end(),print);
    return 0;
}