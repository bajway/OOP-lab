#include <iostream>
using namespace std;

class Person 
{
public:
    string fullName, userID, homeAddress, phoneNumber, email;
    
    Person(string name, string id, string address, string phone, string mail) 
        : fullName(name), userID(id), homeAddress(address), phoneNumber(phone), email(mail) {}

    virtual void showInfo() 
    {
        cout << "Name: " << fullName << endl 
             << "ID: " << userID << endl 
             << "Address: " << homeAddress << endl 
             << "Phone: " << phoneNumber << endl 
             << "Email: " << email << endl;
    }

    void updateInfo(string newAddress, string newPhone, string newEmail) 
    {
        homeAddress = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }
};

class Student : public Person 
{
public:
    string enrolledCourses[10];
    int courseCount = 0;
    double gpa = 0.0;
    int gradYear;

    Student(string name, string id, string address, string phone, string mail, int year) 
        : Person(name, id, address, phone, mail), gradYear(year) {}

    void enrollCourse(string courseName) 
    {
        if (courseCount < 10) 
            enrolledCourses[courseCount++] = courseName;
        else 
            cout << "Max courses reached! Chill bro. 😅" << endl;
    }

    void updateGPA(double newGPA) 
    {
        gpa = newGPA; 
    }

    void showInfo() override 
    {
        Person::showInfo();
        cout << "Grad Year: " << gradYear << endl 
             << "GPA: " << gpa << endl 
             << "Courses Enrolled: ";
        for (int i = 0; i < courseCount; i++) 
            cout << enrolledCourses[i] << endl;
    }
};

class Professor : public Person 
{
public:
    string department;
    string taughtCourses[10];
    int courseCount = 0;
    double monthlyPay;

    Professor(string name, string id, string address, string phone, string mail, string dept, double salary) 
        : Person(name, id, address, phone, mail), department(dept), monthlyPay(salary) {}

    void addCourse(string courseName) 
    {
        if (courseCount < 10) 
            taughtCourses[courseCount++] = courseName;
        else 
            cout << "Too many courses! Take a break. 🫠" << endl;
    }

    void showInfo() override 
    {
        Person::showInfo();
        cout << "Department: " << department << endl 
             << "Salary: $" << monthlyPay << endl 
             << "Courses Teaching: ";
        for (int i = 0; i < courseCount; i++) 
            cout << taughtCourses[i] << endl;
    }
};

class Staff : public Person 
{
public:
    string department, jobTitle;
    double salary;

    Staff(string name, string id, string address, string phone, string mail, string dept, string role, double salary) 
        : Person(name, id, address, phone, mail), department(dept), jobTitle(role), salary(salary) {}

    void showInfo() override 
    {
        Person::showInfo();
        cout << "Department: " << department << endl 
             << "Position: " << jobTitle << endl 
             << "Salary: $" << salary << endl;
    }
};

class Course 
{
public:
    string courseID, courseTitle, schedule;
    int creditHours;
    Professor* instructor;
    Student* enrolledStudents[50];
    int studentCount = 0;

    Course(string id, string title, int credits, string sched, Professor* prof) 
        : courseID(id), courseTitle(title), creditHours(credits), schedule(sched), instructor(prof) {}

    void registerStudent(Student* student) 
    {
        if (studentCount < 50) 
        {
            enrolledStudents[studentCount++] = student;
            student->enrollCourse(courseTitle);
        } 
        else 
            cout << "Class full! No more seats. 😭" << endl;
    }

    void showCourseInfo() 
    {
        cout << "Course ID: " << courseID << endl 
             << "Course Name: " << courseTitle << endl 
             << "Credits: " << creditHours << endl 
             << "Schedule: " << schedule << endl 
             << "Instructor: " << instructor->fullName << endl 
             << "Enrolled Students: ";
        for (int i = 0; i < studentCount; i++) 
            cout << enrolledStudents[i]->fullName << endl;
    }
};

int main() {
    Professor prof("Mr. Sameer", "CS1004", "Fast University", "12345678", "sameer.faisal@nu.edu.pk", "OOP", 200000);
    prof.addCourse("CS1004");

    Student s1("Baqar", "0006", "govt College", "9876543", "k240006@nu.edu.pk", 2024);
    Student s2("Kashif", "2539", "Malir Cantt College", "2345678", "k242539@nu.edu.pk", 2024);

    Course cs1004("CS1004", "Object-Oriented Programming", 3, "FRI 11 AM - 1 PM", &prof);
    cs1004.registerStudent(&s1);
    cs1004.registerStudent(&s2);

    cout << endl << "\t Professor Info 🧑‍🏫 \t" << endl;
    prof.showInfo();

    cout << endl << "\t Student Info 🎓 \t" << endl;
    s1.showInfo();
    s2.showInfo();

    cout << endl << "\t Course Info 📚 \t" << endl ;
    cs1004.showCourseInfo();

    return 0;
}
