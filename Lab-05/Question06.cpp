#include <iostream>

using namespace std;

class LoanHelper{
private:
    double loanAmount;
    int months;
    const double interestRate;

public:
    LoanHelper(double amount, int numMonths, double rate): loanAmount(amount), months(numMonths), interestRate(rate){
        if (interestRate < 0.0 || interestRate > 0.005){
            cout << "Interest rate must be between 0% and 0.5%" << endl;
            exit(0);
        }
    }
    void calculateMonthlyPayment() const{
        double monthlyPayment = (loanAmount / months) * (1 + interestRate);
        cout << "You need to pay " << monthlyPayment << " every month for " << months << " months to repay your loan." << endl;
    }
};

int main(){
    
    LoanHelper loan1(120000, 10, 0.005); 
    loan1.calculateMonthlyPayment(); 
    LoanHelper loan2(5000, 10, 0.002); 
    loan2.calculateMonthlyPayment(); 
    return 0;
}