#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student 
{
    char name[50];
    int id;
    float gpa;
};

int main() 
{
    int n;

    cout << "Enter Number of students: ";
    cin >> n;
    
    cin.ignore();
    
	Student* students = new Student[n];
	
    for (int i = 0; i < n; ++i) 
	{
        cout << "\nStudent " << i + 1 << ":\n";
        
        cout << "namee: ";
        cin.getline(students[i].name, 50);

        cout << "id number: ";
        cin >> students[i].id;

        cout << "cgpa: ";
        cin >> students[i].gpa;
        cin.ignore();
    }
    
    ofstream outFile("students.dat", ios::binary);
    
    if (!outFile) 
	{
        cerr << "error";
        return 1;
    }
    
    outFile.write(reinterpret_cast<char*>(students), n * sizeof(Student));
    
    outFile.close();
    
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) 
	{
        cerr << "error";
        return 1;
    }
    
    Student* readStudents = new Student[n];
    
    inFile.read(reinterpret_cast<char*>(readStudents), n * sizeof(Student)); 
    inFile.close();
    
    cout << "Records from file:\n";
    for (int i = 0; i < n; ++i) 
	{
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: " << readStudents[i].name << endl;
        cout << "ID: " << readStudents[i].id << endl;
        cout << "CGPA: " << readStudents[i].gpa << endl;
    }
    delete[] students;
    delete[] readStudents;
    return 0;
}