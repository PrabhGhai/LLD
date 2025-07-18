#include<iostream>
#include<mutex>
using namespace std;

class Singleton{
    private:
        static Singleton *instance;
        static mutex mtx;
        Singleton()
        {
            cout << "Constructor called"<<endl;
        }
    public:
        static Singleton* getInstance()
        {
            if(instance == nullptr)
            {
                lock_guard<mutex> lock(mtx);
                if(instance == nullptr)
                {
                  instance = new Singleton();
                }
                
            }
            return instance;
        }

};

Singleton *Singleton::instance = nullptr;
mutex Singleton :: mtx;

int main(){

    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();

    cout<<a <<endl;
    cout << b;
    
    return 0;
}
