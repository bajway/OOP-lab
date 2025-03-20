/* You’ve been assigned the ultimate challenge: developing a school management program that
actually keeps track of students and teachers (because, apparently, shouting names during roll call
isn’t efficient). You start with a Person class, because everyone in a school—students, teachers,
and that one mysterious janitor—has a name and an age. But life gets more complicated! Students
have a student ID (to misplace their library books officially) and a grade level (because calling
everyone "kid" isn't ideal), while teachers have a subject (which they lecture about with varying
enthusiasm) and a room number (where they trap students for extra assignments). Naturally, you
create Student and Teacher classes that inherit from Person and add their own special attributes.
But here’s where things get really wild: you need a GraduateStudent class that inherits from both
Student and Teacher, because some poor souls are both students AND teaching assistants—learning
by day, grading papers by night, and questioning their life choices at all times. Finally, in your main
function, you create a GraduateStudent object and display its details, because if they have to suffer
through hybrid inheritance, the least you can do is let them see their own existence printed out.
Now, grab your keyboard, embrace the chaos of multiple inheritance, and let’s make this school
system as smart as the overworked graduate students running it!*/
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
