/*Problem: A fitness app wants to help users track calories burned during activities like
running and cycling. Each activity requires unique calculations (e.g., distance vs. speed), but
the app must present results consistently. The system should allow adding new activities
(e.g., swimming) in the future.
Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.
• Derived Class Cycling:

o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity.*/
#include <iostream>
using namespace std;

class Activity
{
public:
    virtual void calculateCaloriesBurned() = 0;
};

class Running : public Activity
{
private:
    double distance;
    double time;

public:
    Running(double d, double t) : distance(d), time(t) {}
    void calculateCaloriesBurned() override
    {
        cout << "Calories burned while Running: " << 60 * distance << endl;
    }
};
class Cycling : public Activity
{
    double speed;
    double time;

public:
    Cycling(double s, double t) : speed(s), time(t) {}
    void calculateCaloriesBurned() override
    {
        cout << "Calories burned while Cycling: " << 30 * speed * (time / 60.0) << endl;
    }
};

int main()
{
    Running run(5.6, 30);
    Cycling cycle(10.5, 45);
    run.calculateCaloriesBurned();
    cycle.calculateCaloriesBurned();
    return 0;
}