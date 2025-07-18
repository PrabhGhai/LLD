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
    
        Singleton(const Singleton &) = delete;   // Prevent copying like: Singleton s2 = s1;
        Singleton &operator=(const Singleton &) = delete;   // Prevent assignment like: s3 = s1;

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
