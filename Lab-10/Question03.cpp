#include<iostream>
#include<fstream>

using namespace std;
int main(){
    string name, email;
    int totalUser=3;
    ofstream write("signup.txt", ios::app);
    cout << "Enter the Name: " << endl;
    getline(cin, name);
    cout << "Enter the email: " << endl;
    getline(cin, email);
    for (int i = 0; i < totalUser; i++)
    {
        write << name << endl;
        write << email << endl;
    }
    return 0;
}