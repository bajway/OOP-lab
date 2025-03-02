#include <iostream>
#include <string>
using namespace std;

class DayOfYear{
private:
    int day;
    static string months[];
    static int daysInMonth[];
public:
    DayOfYear(int dayOfYear) : day(dayOfYear){}
    void print(){
        int monthIndex = 0;
        int dayOfMonth = day;

        while (dayOfMonth > daysInMonth[monthIndex])
        {
            dayOfMonth -= daysInMonth[monthIndex];
            monthIndex++;
        }

        cout << months[monthIndex] << " " << dayOfMonth << endl;
    }
};

string DayOfYear::months[] =
{
    "Jan", "Feb", "March", "April", "May", "June",
    "July", "August", "Sept", "Oct", "Nov", "Dec"
};

int DayOfYear::daysInMonth[] ={
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 //num of days in each month
};

int main(){
    DayOfYear day1(2);
    day1.print();  //prints Jan 2

    DayOfYear day2(365);
    day2.print();  //prints Dec 31

    DayOfYear day3(60);
    day3.print();  //prints march 1

    return 0;
}