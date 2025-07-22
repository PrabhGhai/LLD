#include<iostream>
using namespace std;

class HttpRequest{
    private:
        string url;
        string method;
        string body;
        HttpRequest() {};

    public:
        friend class HttpRequestBuilder;
        void execute()
        {
            cout << "Api hit for url " << url;
        }
};

class HttpRequestBuilder{
     private:
         HttpRequest req;
     public:
         HttpRequestBuilder &withUrl(const string &url)
         {
             req.url = url;
             return *this;
         }
     HttpRequestBuilder& withMethod(const string &method)
     {
         req.method = method;
         return *this;
     }

     HttpRequestBuilder& withBody(const string &body)
     {
         req.body = body;
         return *this;
     }

     HttpRequest build()
     {
        if(req.url.empty())
        {
            throw runtime_error("Url can't be empty");
        }

        return req;
     }
};

class HttpRequestDirector{
    public:
    static  HttpRequest getMethod(const string&url)
    {
        return HttpRequestBuilder().withUrl(url).withMethod("GET").build();
    }

    static HttpRequest postMethod(const string&url , const string&body)
    {
        return HttpRequestBuilder().withUrl(url).withMethod("POST").withBody(body).build();
    }

};

int main()
{
    HttpRequest req = HttpRequestBuilder().withUrl("http://localhost:1000/api/v1/posts").withMethod("POST").withBody("{message:Hello World}").build();
    req.execute();

    cout << endl;
    cout << "GET Request"<<endl;
    HttpRequest get = HttpRequestDirector::getMethod("diizender.com/api/v1/posts");
    get.execute();
    cout << endl;
    cout << "POST Request"<<endl;
    HttpRequest post = HttpRequestDirector::postMethod("diizender.com/api/v1/add-post","A new post");
    post.execute();
    return 0;
}