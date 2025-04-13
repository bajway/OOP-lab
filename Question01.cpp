/*Imagine you're driving on a long road trip, but instead of focusing on the road, you're too busy
trying to remember the classic formula: Distance = Speed × Time. To make life easier (and to avoid
any unnecessary mental gymnastics while driving), let's create two C++ classes—Speed and
Time—to store speed in km/h and time in hours, respectively. Now, because these two are a bit
shy and like to keep their data private, we’ll introduce them to a mutual friend, a friend function
called calculateDistance(), which will sneakily access their private members and compute the total
distance traveled. The goal? Write a C++ program where the calculateDistance() function takes
values from both classes (say, a speed of 60 km/h and a duration of 2 hours) and calculates how
far you've traveled. Finally, in the main() function, instantiate objects with these values and print
out the result*/
#include<iostream>
using namespace std;
class Time;
class Speed{
    private:
        double speed;
        friend double calculateDistance(Speed, Time);
    public:
        Speed(double s): speed(s){}
};
class Time{
    private:
        double time;
        friend double calculateDistance(Speed, Time);
    public:
        Time(double t): time(t){}
};

double calculateDistance(Speed s, Time t){
    double distance;
    distance = s.speed * t.time;
    return distance;
}
int main(){
    Speed s_obj(60);
    Time t_obj(2);
    cout << "The total distance covered (in km) will be: " << calculateDistance(s_obj, t_obj);
    return 0;
}
