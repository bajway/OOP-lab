#include<iostream>
#include<fstream>

using namespace std;

int main(){
    string name;
    string shortMessage;
    cout << "Enter Recipients name: " << endl;
    cin >> name;
    cin.ignore();
    cout << "Enter a short message: " << endl;
    
    getline(cin, shortMessage);
    ofstream write("greeting.txt");
    write << "Dear " << name << ", " << endl
          << shortMessage << endl
          << "Best Regards!";
    return 0;
}

