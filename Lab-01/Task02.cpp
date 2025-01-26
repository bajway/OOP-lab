/*Create a C++ program to handle student marks management. The program should allow users to
input marks for students in four courses: PF, OOP, DLD & ICT. It should then calculate the total
marks, average marks, and determine the grade for each student based on their average.
Use the following grading metrics:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F*/
#include<iostream>
using namespace std;

int main(){
    int choice, storeMarks[4];
    float marks,avgMarks, totalMarks=0;
    do
    {
        cout << "********STUDENT MARKS MANGEMENT SYSTEM********" << endl;
        cout << "\n";
        cout << "1. PF Marks" << endl;
        cout << "2. OOP Marks" << endl;
        cout << "3. DLD Marks" << endl;
        cout << "4. ICT Marks" << endl;
        cout << "5. Exit" << endl;
        cout << "Please select from the menu, 5 to exit the menu" << endl;
        cin >> choice;
    
    switch (choice)
    {
    case 1:
        cout << "Enter the marks obtained in PF: ";
        cin >> marks;
        if (marks>0){
            totalMarks += marks;
        }
        else{
            cout << "Invalid marks!" << endl;
        }
        break;
    case 2:
        cout << "Enter the marks obtained in OOP: ";
        cin >> marks;
        if (marks>0 && marks<=100){
            totalMarks += marks;
        }
        else{
            cout << "Invalid marks!" << endl;
        }
        break;
     case 3:
        cout << "Enter the marks obtained in DLD: ";
        cin >> marks;
        if (marks>0 && marks<=100){
            totalMarks += marks;
        }
        else{
            cout << "Invalid marks!" << endl;
        }
        break;
     case 4:
        cout << "Enter the marks obtained in ICT: ";
        cin >> marks;
        if (marks>0 && marks<=100){
            totalMarks += marks;
        }
        else{
            cout << "Invalid marks!" << endl;
        }
        break;
        case 5:
            cout << "Exiting the Menu..." << endl;
            break;
    
    
    default:
        cout << "Please select from the menu provided!" << endl;
        break;
    }
    }
    while (choice!=5);
    cout << "Total Marks (out of 400) are: " << totalMarks << endl;
    avgMarks = totalMarks / 4;
   if (avgMarks>=90 && avgMarks<=100)
   {
       cout << "You achieved A grade" << endl;
   }
   else if (avgMarks>=80 && avgMarks<=89)
   {
    cout << "You achieved B grade" << endl;
   }
   else if (avgMarks>=70 && avgMarks<=79)
   {
    cout << "You achieved C grade" << endl;
   }
   else if (avgMarks>=60 && avgMarks<=69)
   {
    cout << "You achieved D grade" << endl;
   }
   else
   {
       cout << "You Failed, F grade" << endl;
   }
   
   
   
}
