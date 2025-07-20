#include<iostream>
using namespace std;

class Burger{
 public:
     virtual void prepare() = 0 ;
};

class BasicBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Basic Burger ";
    }
};
class StandardBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Standard Burger ";
    }
};
class PremiumBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Premium Burger ";
    }
};
class BasicWheatBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Basic Wheat Burger ";
    }
};
class StandardWheatBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Standard Wheat Burger ";
    }
};
class PremiumWheatBurger : public Burger{
    void prepare() override
    {
        cout << "Preparing Premium Wheat Burger ";
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string &type) = 0;
};

class SinghBurger : public BurgerFactory{
    Burger* createBurger(string &type) override
    {
        if(type == "Basic")
        {
            return new BasicBurger;
        }else if(type == "Standard")
        {
            return new StandardBurger;
        }else{
            return new PremiumBurger;
        }
    }
};

class KingBurger : public BurgerFactory{
    Burger* createBurger(string &type) override
    {
        if(type == "Basic")
        {
            return new BasicWheatBurger;
        }else if(type == "Standard")
        {
            return new StandardWheatBurger;
        }else{
            return new PremiumWheatBurger;
        }
    }
};
int main()
{
    string type = "Standard";
    BurgerFactory *burger1 = new SinghBurger;
    Burger * b1 = burger1->createBurger(type);
    b1->prepare();

    //------------------------------------------
    cout << endl;
    BurgerFactory *burger2 = new KingBurger;
    Burger * b2 = burger2->createBurger(type);
    b2->prepare();
    return 0;
}