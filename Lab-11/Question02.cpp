#include<iostream>
using namespace std;

int main(){
    int num1, num2, result;
    cout << "Enter numerator: ";
    cin >> num1;
    cout << "Enter Denominator: ";
    cin >> num2;
    try
    {
        if(num2==0)
            throw "Division by Zero is not allowed!";
        else
            result = num1 / num2;
        cout << "Result: " << result << endl;
    }
    catch(const char* msg)
    {
        cout << "Error! " << msg;
    }
    return 0;
}