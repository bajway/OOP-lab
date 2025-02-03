/*Create a program that moonlights as a basic calculator, wielding the power of pointer
arithmetic to crunch numbers like a pro. It should charm the user into entering two integers,
perform addition, subtraction, multiplication, or division (depending on the user's mood),
and then proudly display the result. Use pointers to juggle values between functions and
make the magic happen.*/
#include<iostream>

using namespace std;
int addNum(int *, int *);
int subNum(int *, int *);
int multNum(int *, int *);
float divNum(int *, int *);

int main(){
    int a, b;
    char op;// operator
    cout << "Enter the First  integer number:";
    cin >> a;
    cout << "Enter the Second integer number:";
    cin >> b;
    cout << "Enter the operator you want to perform(i.e: +, -, * or /):";
    cin >> op;
    int *ptr1 = &a;
    int *ptr2 = &b;
    switch (op)
    {
    case '+':
        cout << "Sum of the numbers is: " << addNum(ptr1, ptr2) << endl;
        break;

    case '-':
         cout << "Subtraction of the numbers is: " << subNum(ptr1, ptr2) << endl;
         break;

    case '*':
         cout << "Product of the numbers is: " << multNum(ptr1, ptr2) << endl;
         break;

    case '/':
        if(b!=0)
            cout << "Division of the numbers is: " << divNum(ptr1, ptr2) << endl;
        else
            cout << "Error, number approaches infinity!" << endl;
        break;

    default:
        cout << "Please enter a valid operator!" << endl;
        break;
    }
}
int addNum(int *x, int *y){
    int result;
    result = *x + *y;
    return result;
}
int subNum(int *x, int *y){
    int result;
    result = *x - *y;
    return result;
}
int multNum(int *x, int *y){
    int result = (*x) * (*y);
    return result;
}
float divNum(int *x, int *y){
    float result;
    result = *x / *y;
    return result; 
}

