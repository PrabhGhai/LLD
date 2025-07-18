#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;
int sum = 0;
void print()
{
    
    mtx.lock();
    for (int i = 0; i < 10000000;i++)
    {
        sum++;
    }
    mtx.unlock();
}
int main()
{
    thread t1(print);
    thread t2(print);
    t1.join();
    t2.join();
    cout << sum;
    return 0;
}
