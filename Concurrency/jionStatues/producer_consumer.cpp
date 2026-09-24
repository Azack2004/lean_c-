#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
std::condition_variable cv_stop;
static bool producer_finished = false;
static int c_stop = 0;
static int sum = 0;
void producer()
{
    bool notify_flag = false;
    int a = 0;
    while(a<101)
    {
        {
            std::lock_guard lock(mtx);
            notify_flag = q.empty();
            q.push(a);
        }
        if(notify_flag)
        {
            cv.notify_one();
        }
        std::cout<<"produce:"<<a<<std::endl;
        a++;
    }
    std::unique_lock lock(mtx);
    cv_stop.wait(lock ,[](){
        return sum == 5050;
    });
    c_stop = 1;
    cv.notify_one();
    //生产完毕，更新标记并通知消费者
    // {
    //     std::lock_guard<std::mutex> lock(mtx);
    //     producer_finished = true;
    // }
    // cv.notify_one(); // 唤醒消费者让其知道生产已结束

    // // 等待消费者计算完毕
    // std::unique_lock<std::mutex> lock(mtx);
    // cv_stop.wait(lock, [](){
    //     return sum == 5050;
    // });
}

void consumer()
{
  
    while(true)
    {
        std::unique_lock lock(mtx);
        cv.wait(lock,[](){
            return !q.empty()||c_stop;
        });
        if(c_stop&&q.empty())
        {
            break;
        }
        std::cout<<"consumer:"<<q.front()<<std::endl;
        sum+=q.front();
        q.pop();
        if(sum==5050)
        {
        
            cv_stop.notify_one();
        }
        
     
    }
    //------------
    // while(true)
    // {
    //     std::unique_lock<std::mutex> lock(mtx);
        
    //     // 等待条件：队列不为空 OR 生产者已结束
    //     cv.wait(lock, [](){
    //         return !q.empty() || producer_finished;
    //     });

    //     // 如果队列为空且生产者已结束，跳出循环
    //     if (q.empty() && producer_finished) {
    //         break;
    //     }

    //     int val = q.front();
    //     q.pop();
    //     sum += val;
    //     std::cout << "consumer: " << val << std::endl;

    //     if(sum == 5050)
    //     {
    //         cv_stop.notify_one();
    //     }
    // } // 出作用域，lock 自动释放，绝对不会出现无锁 wait 或重复 unlock 的问题

} 
int main()
{
    std::thread t(consumer);
    producer();
    
    t.join();
    std::cout << "Final Sum: " << sum << std::endl;
    return 0;
}