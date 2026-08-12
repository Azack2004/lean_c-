#include<iostream>
#include<string>
int main()
{   
    int arr_2d[2][3]=
    {
        {1,2,3},
        {2,3,4}
    };//行集合
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<arr_2d[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<sizeof(arr_2d)<<std::endl;
    int arr2[][2]={1,2,3,4,5};
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            std::cout<<arr2[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<sizeof(arr2[0])<<std::endl;
    std::cout<<"二维数组的行数"<<sizeof(arr2)/sizeof(arr2[0])<<std::endl;
    std::cout<<"二维数组的列数"<<sizeof(arr2[0])/sizeof(arr2[0][0])<<std::endl;
    std::cout<<"二维数组首地址"<<arr2<<" "<<arr2[0]<<" "<<arr2[1]<<std::endl;
    int arr3[][3]={100,100,100,90,50,100,60,70,80};
    int arr[3];
    int arr_l[]={0,0,0};
    std::string name[]={"张三","李四","王武"};
    //  思维方式的问题。
    for(int i=0;i<sizeof(arr3)/sizeof(arr3[0]);i++)
    {   
        arr[i]=0;
        
        for(int j =0;j<sizeof(arr3[0])/sizeof(arr3[0][0]);j++)
        {   
            std::cout<<arr3[i][j]<<" ";
            arr[i]+=arr3[i][j];
            arr_l[j]+=arr3[i][j];
            
        }
        
        std::cout<<std::endl;
        

    }
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {   

        std::cout<<name[i]<<"成绩是："<<arr[i]<<std::endl;
        std::cout<<arr_l[i]<<std::endl;
    }
    return 0;
}