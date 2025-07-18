#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name,double price)
    {
        this->name = name;
        this->price = price;
    }

};

//Only cart related logic in cart
class Cart{
    private:
        vector<Product*>products;
    public:
          // add product to cart
          void addProduct(Product *p)
          {
              products.push_back(p);
          }

          //get products
          vector<Product*> getProducts()
          {
              return products;
          }
          //cal Price of cart
          double calTotalPrice()
          {
              double sum = 0;
              for (auto itr : products)
              {
                  sum += itr->price;
              }
              return sum;
          }
};

class CartInvoice{
   private:
       Cart *cart;
   public:
   CartInvoice(Cart *c)
   {
       this->cart = c;
   }

   void printInvoice()
   {
     cout << "Shopping Cart Invoice:\n";

     for(auto p:cart->getProducts())
     {
         cout << p->name << " " << "Rs. " << p->price;
         cout << endl;
     }
   }

};

// asbstract class for persisting cart data
class DBPersistance{

    public:
    virtual void save(Cart* cart) = 0; // Pure virtual function
};

class SqlStorage : public DBPersistance{

    public:
    void save(Cart* cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};
class MongoStorage : public DBPersistance{

    public:
    void save(Cart* cart) override {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }
};

int main()
{
    Cart *cart = new Cart();
    cart->addProduct(new Product("Laptop", 5000));
    cart->addProduct(new Product("Mobile", 17000));

    CartInvoice *inv = new CartInvoice(cart);
    inv->printInvoice();
    cout << endl;
    DBPersistance *db = new SqlStorage();
    db->save(cart);
     DBPersistance *mongoDb = new MongoStorage();
    mongoDb->save(cart);
    return 0;
}
