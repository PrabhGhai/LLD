#include<iostream>
#include<thread>
using namespace std;

int sum = 0;
void print()
{
    for (int i = 0; i < 10000000;i++)
    {
        sum++;
    }
}
int main()
{
    thread t1(print);
    thread t2(print);
    t1.join();
    t2.join();
    //Gives different results everytime
    cout << sum;
    return 0;
}
