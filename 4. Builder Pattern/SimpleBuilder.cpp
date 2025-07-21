#include<iostream>
#include<map>
using namespace std;

class HttpRequest{
    private:
    string url;
    string method;
    map<string, string> headers;
    map<string,string> queryParams;
    string body;
    int timeout; // in seconds
    HttpRequest() {};

    public:
        friend class HttpRequestBuilder;

        void execute()
        {
            cout << "Method to execute http request";
        }
};

class HttpRequestBuilder{

     private:    
        HttpRequest req;

    public:
    //Method Chaining
     HttpRequestBuilder & withUrl(const string &u)
    {
        req.url = u;
        return *this;
    }
    HttpRequestBuilder & withMethod(const string &u)
    {
        req.method = u; 
        return *this;
    }
    HttpRequestBuilder& withHeader(const string& key,const string& value) {
        req.headers[key] = value;
        return *this;
    }

    HttpRequestBuilder& withQueryParams(const string& key,const  string& value) {
        req.queryParams[key] = value;
        return *this;
    }
    
    HttpRequestBuilder& withBody(const string& body) {
        req.body = body;
        return *this;
    }
    
    HttpRequestBuilder& withTimeout(const int timeout) {
        req.timeout = timeout;
        return *this;
    }

    // Build method to create the immutable HttpRequest object
    HttpRequest* build() {
        // Validation logic can be added here
        if (req.url.empty()) {
            throw runtime_error("URL cannot be empty");
        }
        return &req;
    }

   


};

int main()
{
    HttpRequest *request = HttpRequestBuilder().withUrl("https://api.example.com")
        .withMethod("POST")
        .withHeader("Content-Type", "application/json")
        .withHeader("Accept", "application/json")
        .withQueryParams("key", "12345")
        .withBody("{\"name\": \"Aditya\"}")
        .withTimeout(60)
        .build();
        request->execute(); // Guaranteed to be in a consistent state
    return 0;
}