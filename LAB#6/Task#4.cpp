#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(string personName, int personAge) : name(personName), age(personAge) {}
    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << "\n";}
};
class Student : virtual public Person {
protected:
    int studentID;
    int gradeLevel;
public:
    Student(string studentName, int studentAge, int id, int grade)
        : Person(studentName, studentAge), studentID(id), gradeLevel(grade) {}
    void displayStudent() const {
        cout << "Student ID: " << studentID << "\nGrade Level: " << gradeLevel << "\n"; }
};
class Teacher : virtual public Person {
protected:
    string subject;
    int roomNumber;
public:
    Teacher(string teacherName, int teacherAge, string teacherSubject, int room): Person(teacherName, teacherAge), subject(teacherSubject), roomNumber(room) {}
    void displayTeacher() const {
        cout << "Subject: " << subject << "\nRoom Number: " << roomNumber << "\n";
    }
};
class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(string gradName, int gradAge, int gradID, int grade, string gradSubject, int gradRoom): Person(gradName, gradAge), Student(gradName, gradAge, gradID, grade), Teacher(gradName, gradAge, gradSubject, gradRoom) {}
    void displayGraduateStudent() const {
        cout << "Graduate Student:\n";
        displayPerson();
        displayStudent();
        displayTeacher(); }
};
int main() {
    GraduateStudent grade("Kashif", 20, 2539, 4, "AI", 23);
    grade.displayGraduateStudent();
    return 0; }
