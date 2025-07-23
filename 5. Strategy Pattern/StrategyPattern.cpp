#include<iostream>
using namespace std;

class Walk
{
    public:
      virtual void walk() = 0;
       virtual ~Walk() {}
};
class Talk{
    public:
      virtual void talk() = 0;
      virtual ~Talk() {}
};
class Fly{
    public:
      virtual void fly() = 0;
      virtual ~Fly() {}
};

class NormalWalk : public Walk{
    void walk() override
    {
        cout << "Normal Walk of Robot";
    }
};

class NoWalk : public Walk{
    void walk() override
    {
        cout << "Robot can't walk";
    }
};

class NormalTalk : public Talk{
    void talk() override
    {
        cout << "Normal Talk of  Robot";
    }
};

class NoTalk : public Talk{
    void talk() override
    {
        cout << "Robot can't talk";
    }
};

class NormalFly : public Fly{
    void fly() override
    {
        cout << "Normal Fly of  Robot";
    }
};

class FlyWithJet : public Fly{
    void fly() override
    {
        cout << "Robot can fly with JET";
    }
};
class Robot{
    protected:
        Walk *walk;
        Talk *talk;
        Fly *fly;

    public:
    Robot(Walk *walk, Talk *talk, Fly *fly)
    {
        this->walk = walk;
        this->talk = talk;
        this->fly = fly;
    }

    void getWalk()
    {
      walk->walk();
    }
     void getTalk()
    {
      talk->talk();
    }
     void getFly()
    {
      fly->fly();
    }

};

int main()
{

    //Run Time Polymorphism
    Robot *robo1 = new Robot(new NormalWalk(), new NormalTalk(), new FlyWithJet());
    robo1->getWalk();
    cout << endl;
    robo1->getTalk();
    cout << endl;
    robo1->getFly();
    return 0;
}