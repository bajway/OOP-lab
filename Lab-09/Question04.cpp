/*Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:
• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.
• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.
• Derived Class DigitalWallet:
o Data Members:
▪ balance (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.*/
#include <iostream>
using namespace std;
class PaymentMethod
{
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
private:
    string cardNo;

public:
    CreditCard(string n) : cardNo(n) {}
    void processPayment(double amount) override
    {
        if (cardNo == "00000-00000-00000")
            cout << "Amount processed:" << amount << endl;
        else
            cout << "Failure!, Enter correct card number" << endl;
    }
};

class DigitalWallet : public PaymentMethod
{
private:
    double balance;

public:
    DigitalWallet(double b) : balance(b) {}
    void processPayment(double amount) override
    {
        if (amount < balance){
            balance -= amount;
            cout << amount << " Deducted from account" << endl
                 << "Remaining balance: " << balance << endl;
        }
        else
            cout << "Insufficient Balance" << endl;
    }
};

int main()
{
    CreditCard cc("00000-00000-00000");
    cc.processPayment(2500);
    DigitalWallet dw(5000);
    dw.processPayment(2500);

    return 0;
}