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
    string get_Day(){
        
    }


};
int main(){

}
