/*Write a C++ program to check whether a given number is prime or not. Allow the user to input a
number and display whether it's prime or not?*/

#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num>0){
    if (num==2 || num==3 || num==5)
    {
        cout << "It is a prime number!" << endl;
    }
    
    else if (num%2==0 || num%3==0 || num%5==0 || num==1)
    {
        cout << "Not a prime number!" << endl;
    }
    else
    {
        cout << "It is a prime number" << endl;
    }
    }
    else
        cout << "Enter a valid number to check!" << endl;
    return 0;
} //end main