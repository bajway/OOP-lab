#include<iostream>
using namespace std;
class WeekDays{
    private:
        string days[7];
        int CurrentDay=0;
    public: 
    WeekDays(){
        this->days[0]= "Monday";
        this->days[1]= "Tuesday";
        this->days[2]="Wednesday";
        this->days[3]="Thursday"
        this->days[4]= "Friday";
        this->days[5]= "Saturday";
        this->days[6]="Sunday";

    }
    WeekDays(int day){
        this->days[0]= "Monday";
        this->days[1]= "Tuesday";
        this->days[2]="Wednesday";
        this->days[3]="Thursday"
        this->days[4]= "Friday";
        this->days[5]= "Saturday";
        this->days[6]="Sunday";
        CurrentDay =day % 7;
    }
string getCurrentDay()  
        {
            return Days[CurrentDay] ;
        }
        string getNextDay() 
        {
            return Days[(CurrentDay + 1) % 7] ;
        }
        string getPreviousDay()  
        {
            return Days[(CurrentDay + 6) % 7] ;
        }
        string getNthDayFromToday(int N)
        {
            return Days[(CurrentDay + N) % 7] ;
        }
} ;
int main() 
{
    WeekDays day1 ;
    cout<<"Current Day:"<<day1.getCurrentDay()<<"\n" ;
    cout<<"Next Day:"<<day1.getNextDay()<<"\n" ;
    cout<<"Previous Day:"<<day1.getPreviousDay()<<"\n" ;
    cout<<"20 Days From Today:"<< day1.getNthDayFromToday(20)<<"\n\n" ;
    WeekDays day2(8) ;
    cout<<"Current Day:"<<day2.getCurrentDay()<<"\n" ;
    cout<<"Next Day:"<<day2.getNextDay()<< "\n" ;
    cout<<"Previous Day:"<<day2.getPreviousDay()<<"\n" ;
    cout<<"20 Days From Today:"<<day2.getNthDayFromToday(20)<<"\n" ;
    return 0 ; 
}
