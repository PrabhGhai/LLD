#include<iostream>
using namespace std;

class Singleton{
    private:
        static Singleton *instance;
         Singleton()
        {
            cout << "Constructor called\n";
        }
    public:
    static Singleton* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton *a = Singleton::getInstance();
    Singleton *b = Singleton::getInstance();
    cout << a;
    cout << endl;
    //Referencing to the same object.
    cout << endl;
    return 0;
}