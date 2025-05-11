#include<iostream>
using namespace std ;
class BankAccount
{
    private:
        int balance ;
    public:
        BankAccount(int balance) : balance(balance) {}
        void withdraw(int amount)
        {
            try
            {
                if(amount>balance)
                {
                    throw "InsufficientFundsException" ;
                }
                else
                {
                    balance = balance - amount ;
                    cout<<"Transaction Successful, New Balance:"<<balance<<endl ;
                }
            }
            catch(const char* exception)
            {
                cout<<"Insufficient Funds!!!"<<endl ;
            }
        }
} ;
int main()
{
    BankAccount account(5000) ;
    account.withdraw(3000) ;
    account.withdraw(4000) ;
    return 0 ;
}