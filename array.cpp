#include<iostream>
int main()
{   
    int num_arr[]={100,200,379,170,90,800,1000,2,3,5,6};
    int max= 0;
    int len = sizeof(num_arr)/sizeof(num_arr[0]);

    std::cout<<"找最大"<<std::endl;
    for(int i=0;i<len;i++)
    {
        if(num_arr[i]>max)
        {
            max=num_arr[i];
        }
    }
    std::cout<<max<<std::endl;

    std::cout<<"数组反转"<<std::endl;
    for(int i=0;i<len/2;i++)
    {
        int j = num_arr[i];
        num_arr[i]=num_arr[len-1-i];
        num_arr[len-1-i]=j;
    }

    
    for(int i=0;i<len;i++)
    {
       std::cout<<num_arr[i]<<std::endl; 
    }
    std::cout<<"冒泡排序"<<std::endl;
    // int slow =0;
    // int fast =0;
    // while(slow<len-1)
    // {
    //     while(fast<len)
    //     {
    //         if(num_arr[slow]>num_arr[fast])
    //         {
    //             int j =num_arr[fast];
    //             num_arr[fast]=num_arr[slow];
    //             num_arr[slow]=j;
    //         }
    //         fast++;
    //     } 
    //     slow++;
    //     fast=slow;
    // }
    
    for(int i=0;i<len-1;i++)
    {   bool swapped = false; // 标记本轮是否发生过交换
    
        for(int s=0;s<len-1-i;s++ )
        {
            if(num_arr[s]>num_arr[s+1])
            {
                int j =num_arr[s+1];
                num_arr[s+1]=num_arr[s];
                num_arr[s]=j;
                bool swapped = true; // 标记本轮是否发生过交换
    
            }
        }
        if(swapped)
        {
            break;
        }
       
    }
    
    


    for(int i=0;i<len;i++)
    {
       std::cout<<num_arr[i]<<std::endl; 
    }
    
    


    return 0;
}