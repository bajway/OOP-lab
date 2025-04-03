#include<iostream>
#include<string>
using namespace std;

class Account{
    protected:
        int accountNumber;
        float balance;
        string accountHolderName;
    public:
        Account(int accNo, double b, string name): accountNumber(accNo), balance(b), accountHolderName(name){}
        virtual void deposit(double amount){
                balance += amount;
                cout << "Deposited: " << amount << "\n New Balance: " << balance << endl;
        }
        virtual void withdraw(double amount) = 0;
        virtual double calculateInterest() = 0;
        virtual void printStatement() const{
            cout << "Account Statement of " << accountHolderName << " Account No:( " << accountNumber << ")\n Current Balance: Rs" << balance << endl;
        }
        virtual ~Account(){};
};

class SavingsAccount: public Account{
        double interestRate;
        double minimumBalance;
    public:
        SavingsAccount(int accNo, double b, string name, double iRate, double minb) : Account(accNo, b, name),
        interestRate(iRate), minimumBalance(minb) {}
        void withdraw (double amount) override{
            if(balance-amount>=minimumBalance){
                balance -= amount;
                cout << "Amount withdrawn: Rs " << amount << " Current Balance: Rs " << balance << endl;
            }
            else{
                cout << "Insufficient Balance !" << endl;
            }
        }
        double calculateInterest() override{
            return balance * (interestRate / 100);
        }
        void printStatement() const override{
            Account::printStatement();
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "Minimum Balance: Rs " << minimumBalance;
        }
};

class CheckingAccount : public Account{
    public:
        CheckingAccount(int accNo, double bal, string name): Account(accNo, bal, name){}
    
        void withdraw(double amount) override{
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
            } else {
                cout << "Insufficient Balance !" << endl;
                
            }
        }
    
        double calculateInterest() override{
            return 0;  //no interest applies
        }
    
        void printStatement() const override{
            Account::printStatement();
            cout << "Checking accounts do not earn interest.\n";
        }
    };
    
    class FixedDepositAccount : public Account {
        private:
            double fixedInterestRate;
            int maturityYears;
        
        public:
            FixedDepositAccount(int accNo, double b, string name, double iRate, int years)
                : Account(accNo, b, name), fixedInterestRate(iRate), maturityYears(years) {}
        
            void withdraw(double amount) override{
                cout << "Withdrawal not allowed until maturity (" << maturityYears << " years).\n";
            }
            double calculateInterest() override{
                return balance * (fixedInterestRate / 100) * maturityYears;
            }
        
            void printStatement() const override{
                Account::printStatement();
                cout << "Fixed Deposit Interest Rate: " << fixedInterestRate << "%" << endl;
                cout << "Maturity Period: " << maturityYears << " years" << endl;
            }
        };
        
        int main() {
            // Create a savings account
            SavingsAccount savings(1001, 4000, "Baqar", 4.0, 100);
            SavingsAccount *saving_ptr;
            saving_ptr->deposit(1000);
            saving_ptr->withdraw(4500);  
            saving_ptr->withdraw(3000);  
            cout << "Interest Earned: $" << saving_ptr->calculateInterest() << endl;
            saving_ptr->printStatement();

            cout << "----------------------" << endl
                 << endl;

            // Create a checking account
            CheckingAccount checking(1002, 2000, "Bob");
            checking.deposit(500);
            checking.withdraw(2500);  
            checking.withdraw(1000);  
            checking.printStatement();
        
            cout << "----------------------" << endl
                 << endl;
            // Create a fixed deposit account
            FixedDepositAccount fixedDep(1003, 10000, "Bajwa", 5.0, 3);
            fixedDep.deposit(500);  
            cout << "Interest Earned: $" << fixedDep.calculateInterest() << endl;
            fixedDep.withdraw(2000); 
            fixedDep.printStatement();
        
            return 0;
        }
        