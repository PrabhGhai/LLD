#include<iostream>
using namespace std;


//Burgers 
class Burger{
        public:
            virtual void prepare() = 0;
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

//GARLIC Bread
class GarlicBread{
    public:
        virtual void prepare() = 0;
};
class BasicGB : public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Basic Garlic Bread ";
    }
};
class StandardGB : public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Standard Garlic Bread ";
    }
};
class PremiumGB : public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Premium Garlic Bread ";
    }
};
class BasicWheatGB : public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Basic Wheat Garlic Bread ";
    }
};
class StandardWheatGB: public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Standard Wheat Garlic Bread ";
    }
};
class PremiumWheatGB: public GarlicBread{
    void prepare() override
    {
        cout << "Preparing Premium Wheat Garlic Bread ";
    }
};

class Factory{
    public:
    virtual Burger *createBurger(string &types) = 0;
    virtual GarlicBread *createGB(string &type)  = 0 ;
};


class SinghBurger :public Factory{
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

    GarlicBread* createGB(string &type)  override
    {
        if(type == "Basic")
        {
            return new BasicGB;
        }else if(type == "Standard")
        {
            return new StandardGB;
        }else{
            return new PremiumGB;
        }
    }
};

class KingBurger :public Factory{
    Burger* createBurger(string &type)  override
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

    GarlicBread* createGB(string &type)  override
    {
        if(type == "Basic")
        {
            return new BasicWheatGB;
        }else if(type == "Standard")
        {
            return new StandardWheatGB;
        }else{
            return new PremiumWheatGB;
        }
    }
};

int main()
{
    string type ="Standard";
    Factory *order1 = new KingBurger;
    Burger* o1B = order1->createBurger(type);
    o1B->prepare();

    //------------------------
    cout << endl;
    GarlicBread *o1GB = order1->createGB(type);
    o1GB->prepare();

    return 0;
}