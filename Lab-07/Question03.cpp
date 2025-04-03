#include <iostream>
using namespace std;

class Currency 
{
public:
    double amt;
    string c_code;
    string c_symbol;
    static double usd;
    static double eur;
    static double pkr;

    Currency(double amt, string code, string symbol) : amt(amt), c_code(code), c_symbol(symbol) {}

    virtual double converter() = 0;

    double convert_cureency(string targetCurrency) 
    {
        double target_c = 1.0;

        if (targetCurrency == "PKR")
            target_c = pkr;
        else if (targetCurrency == "USD")
            target_c = usd;
        else if (targetCurrency == "EUR")
            target_c = eur;
        else
        {
            cout << "Invalid argument, stopping program" << endl;
            return 1;
        }
        return converter() / target_c;
    }
    virtual void display() = 0;
};

// set PKR as the base currency
double Currency::pkr = 1.0;  
double Currency::usd = 280.0; 
double Currency::eur = 300.0;

class Dollar : public Currency 
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$") {}
    double converter() override 
    { 
        return amt * usd; 
    }
    void display() override 
    { 
        cout << c_symbol << amt << " (" << c_code << ")" << endl;
    }
};

class Euro : public Currency 
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€") {}
    double converter() override 
    { 
        return amt * eur; // Convert EUR to PKR
    }
    void display() override 
    { 
        cout << c_symbol << amt << " (" << c_code << ")" << endl; 
    }
};

class Rupee : public Currency 
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs") {}
    double converter() override 
    { 
        return amt; // PKR is already the base
    }
    void display() override 
    { 
        cout << c_symbol << amt << " (" << c_code << ")" << endl; 
    }
};

int main() 
{
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);
    d.display();
    e.display();
    r.display();
    cout << "10000 PKR in USD: " << r.convert_cureency("USD") << " USD" << endl;
    cout << "10000 PKR in EUR: " << r.convert_cureency("EUR") << " EUR" << endl;

    return 0;
}