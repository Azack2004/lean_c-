#include<iostream>
#include<thread>
#include<mutex>
#include<future>
#include<chrono>
void sleep(int a,std::promise<int> &p)
{
   try
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (a < 0)
        {
            throw std::runtime_error("a不能小于0");
        }
        p.set_value(a * a);
    }
    catch (...)
    {
        p.set_exception(std::current_exception());
    } 
}
int main()
{
    // std::future f = std::async(std::launch::async,sleep);
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    // std::cout<<f.get()<<std::endl;
    // std::packaged_task<int(int)> task(sleep);
    // std::future<int> f = task.get_future();

    // // 3. 把 task 移交给子线程去执行
    // // 子线程只管“算”，算完自动把结果填进共享状态
    // std::thread t(std::move(task),1);

    // // 4. 主线程在合适的时候，通过 fut 拿结果
    // std::cout << "Result: " << f.get() << std::endl; // 输出 30

    // t.join();
    std::promise<int> p ;
    std::future<int> f = p.get_future();
    std::thread t(sleep ,-1,std::ref(p));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    try
    {
        std::cout << f.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "主线程捕获异常: "
                  << e.what()
                  << std::endl;
    }
    //std::cout << f.get() << std::endl;
    t.join();
    return 0;
}