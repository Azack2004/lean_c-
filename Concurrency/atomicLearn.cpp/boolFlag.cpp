#include<atomic>
#include<iostream>
int main()
{
    std::atomic<int> x{10};
    int expected = 10;

    bool ok = x.compare_exchange_weak(expected, 20);
    std::cout<<x<<std::endl;
    // 可能出现：
    // ok       == false
    // x        == 10
    // expected == 10
    return 0;
}