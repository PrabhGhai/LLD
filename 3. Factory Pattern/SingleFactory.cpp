#include<iostream>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;
};

class BasicBurger : public Burger{
   public:
   void prepare() override {
       cout << "Basic Burger";
   }
};
class StandardBurger : public Burger{
   public:
   void prepare() override {
       cout << "Standard Burger";
   }
 };

 class PremiumBurger : public Burger{
   public:
   void prepare() override {
       cout << "Premium Burger ";
   }
 };
 
 class BurgerFactory{
    public:
    Burger* createBurger(string &type)
    {
         if(type == "Basic")
         {
             return new BasicBurger();
         }else if(type == "Standard")
         {
             return new StandardBurger();
         }else{
             return new PremiumBurger();
         }
    }
 };

int main()
{
    string type = "Standard";
    BurgerFactory *obj = new BurgerFactory();
    Burger* burger = obj->createBurger(type);
    burger->prepare();
    return 0;
}