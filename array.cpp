#include<iostream>
int main()
{   
    int num_arr1[10];
    for(int i=0;i<10;i++)
    {
        std::cout<<num_arr1[i]<<std::endl;
    }

    int num_arr[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<10;i++)
    {
        std::cout<<num_arr[i]<<std::endl;
    }
    std::cout<<sizeof(num_arr)<<std::endl;

    int num_arr2[]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++)
    {
        std::cout<<num_arr2[i]<<std::endl;
    }
    std::cout<<sizeof(num_arr2)<<std::endl;
    std::cout<<sizeof(num_arr2)/sizeof(num_arr2[0])<<std::endl;
    std::cout<<num_arr1<<std::endl; 
    std::cout<<&num_arr1[0]<<std::endl;
    std::cout<<*(&num_arr2[1]+4)<<std::endl;
    return 0;
}