/*Write a program to take an integer array as an input from user and count all the even and odd
numbers in that list and print the counts.*/
#include<iostream>
using namespace std;

int main(){
    int size, evenCount=0, oddCount=0;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of an array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i]%2==0)
        {
            evenCount++; //even numbers counter
        }
        else if (array[i]%2!=0)
        {
            oddCount++; //odd numbers counter
        }
        else
        {
            continue;
        } 
    }
    // cout << "Original Array: " << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << array[i] << ", ";
    // }
    cout << endl;
    cout << "Total even numbers in the arrays: " << evenCount << endl;
    cout << "Total odd numbers in the arrays: " << oddCount << endl;

    return 0;
}