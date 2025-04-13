/*Meet Student, a class that holds a student's name and their three precious grades—because
what’s school without some academic drama? But wait, students can’t just update their own
grades (obviously), so we bring in Teacher, a class with special access privileges (a.k.a. a friend
class) that can peek into grades, modify them, and perhaps even save students from academic
disaster! To keep things fair and scientific, there’s also a friend function called
calculateAverageGrade() that computes the average grade—because math doesn’t lie (even if
students wish it would). In main(), we’ll simulate a high-stakes grading scenario: first, we’ll display
the student’s grades, then let the teacher graciously update one of them (whether out of
generosity or mercy, who knows?), and finally, we’ll recalculate the average to see if things
improved or got even worse.*/

#include<iostream>
using namespace std;

class Teacher;
class Student{
    private:
        string name;
        double mark1, mark2, mark3;
        friend class Teacher;
        friend double calculateAverageGrade(const Student &s);

    public:
        Student(string n, double m1, double m2, double m3): name(n), mark1(m1), mark2(m2), mark3(m3){}
        void display(){
            cout << "Subject 1 marks: " << mark1 << endl;
            cout << "Subject 2 marks: " << mark2 << endl;
            cout << "Subject 3 marks: " << mark3 << endl;
        }
};

class Teacher{
    
    public:
    void modifyGrade(Student &s, int index, int newM){
        switch(index) {
            case 1: 
                s.mark1 = newM;
                break;
            case 2: 
                s.mark2 = newM; 
                break;
            case 3: 
                s.mark3 = newM; 
                break;
            default: 
                cout << "Invalid grade index!" << endl;
        }
    }
   
};
double calculateAverageGrade(const Student &s){
    double avg = (s.mark1 + s.mark2 + s.mark3) / 3.0;
    return avg;
}

int main(){
    Student s("Kashif", 85, 92, 93);
    s.display();
    cout << "Average Before: " << calculateAverageGrade(s) << endl;
    Teacher t;
    t.modifyGrade(s, 2, 98);
    s.display();
    cout << "Average after: " << calculateAverageGrade(s) << endl;
    return 0;
}