/*Problem: A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.*/
#include<iostream>
using namespace std;

class Vehicle{
    protected:
        string model;
        double rate;
    public:
        Vehicle(const string& mName , double dailyRate): model(mName), rate(dailyRate){}
        virtual double getDailyRate() const = 0;
        virtual void displayDetails() const = 0;
        virtual ~Vehicle() {}
};

class Car: public Vehicle{
    public:
    Car(const string& mName, double dailyRate ): Vehicle(mName, dailyRate){}
    double getDailyRate()const override{
        return rate;
    }
    void displayDetails()const override{
        cout << "Car Model: " << model << endl;
        cout << "Daily Rate: $ " << rate << endl;
    }
};
class Bike: public Vehicle{
    public:
    Bike(const string& mName, double dailyRate): Vehicle(mName, dailyRate){}
    double getDailyRate() const override{
        return rate;
    }
    void displayDetails() const override{
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rate: $ " << rate << endl;
    }
};
int main(){
    Car c("Tesla", 90000.0);
    Bike b("Yamaha H2R", 450000.0);
    c.displayDetails();
    b.displayDetails();
    return 0;
}