#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Forward declaration
class Isubcriber;

// Subject (Channel) interface
class IChannel{
   public:
       virtual void subscribe(Isubcriber* user) = 0;
       virtual void unsubscribe(Isubcriber* user) = 0;
       virtual void notify() = 0;
       virtual ~IChannel() = default;
};

// Observer (Subscriber) interface
class Isubcriber{
public:
    virtual void update(const string& msg) = 0;
    virtual string getName() const = 0;
    virtual ~Isubcriber() = default;
};

// Concrete Subject
class Channel: public IChannel{
    private:
        vector<Isubcriber*> subscribers;
        string latestVideo;
    public:
    void subscribe(Isubcriber* user) override {
        subscribers.push_back(user);
        cout << user->getName() << " subscribed to The Code Master" << endl;
    }
    void unsubscribe(Isubcriber* user) override {
        auto itr = find(subscribers.begin(), subscribers.end(), user);
        if(itr != subscribers.end()) {
            cout << (*itr)->getName() << " unsubscribed from The Code Master" << endl;
            subscribers.erase(itr);
        }
    }
    void notify() override {
        for(Isubcriber* sub: subscribers) {
            sub->update(latestVideo);
        }
    }
    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "New video uploaded: " << videoTitle << endl;
        notify();
    }
};

// Concrete Observer
class Subscriber: public Isubcriber{
    string name;
public:
    Subscriber(const string& n): name(n) {}
    void update(const string& msg) override {
        cout << name << " received notification: " << msg << endl;
    }
    string getName() const override {
        return name;
    }
};

int main()
{
    Channel TCM;
    Subscriber user1("PrabhGhai");
    Subscriber user2("Alice");

    TCM.subscribe(&user1);
    TCM.subscribe(&user2);

    TCM.uploadVideo("Observer Pattern in C++");

    TCM.unsubscribe(&user2);

    return 0;
}