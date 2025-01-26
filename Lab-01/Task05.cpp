/*Write a function that will take a number 'n' input by user and will return its factorial.*/

#include<iostream>
using namespace std;
int factorial(int n);
int main(){
    int number;
    cout << "Enter a number to find its factorial: ";
    cin >> number;
    int fact = factorial(number);
    cout << "Factorial of " << number << " is: " << fact << endl;
}
int factorial(int n){
    int result = 0;
    if (n==0 || n==1){
        return n;
    }
    else{
        result += n *factorial (n - 1);
    }
}