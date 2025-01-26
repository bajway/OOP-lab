/*You are hired as a billing manager at K-Electric. Your task is to calculate the monthly bill
according to the units consumed. Write a program to input electricity unit charge and calculate the
total electricity bill according to the given condition:
For first 50 units Rs. 0.50/unit
For next 100 units Rs. 0.75/unit
For next 100 units Rs. 1.20/unit
For unit above 250 Rs. 1.50/unit
An additional surcharge of 20% is added to the bill.*/
#include<iostream>
using namespace std;

int main(){
    int unitConsumed;
    float billAmount, surcharge;
    cout << "Enter the number of units consumed: ";
    cin >> unitConsumed;
    if (unitConsumed>0)
    {
    if (unitConsumed<=50)
    {
        billAmount = unitConsumed * 0.50;
    }
    else if (unitConsumed>50 && unitConsumed<=150)
    {
        billAmount = 50 * 0.50 + (unitConsumed - 50) * 0.75;
    }
    else if (unitConsumed>150 && unitConsumed<=250)
    {
        billAmount = 50 * 0.50 + 100 * 0.75 + (unitConsumed - 150) * 1.20;
    }
    else
    {
        billAmount = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (unitConsumed - 250) * 1.50;
    }
    surcharge = billAmount * 0.20;
    billAmount += surcharge;
    cout << "Total Electricity bill (including surcharges): Rs. " << billAmount;
    }
    else
    {
        cout << "Please Enter valid number of units";
    }
    return 0;
} /*P.S: was nicely confused before finding out the logic, but after noticing sample output cracked it. Easy but tricky */