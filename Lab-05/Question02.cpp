#include <iostream>
#include <string>
using namespace std;

class Battery{
private:
    int capacity; 
public:
    Battery(int cap) : capacity(cap){}
    int getCapacity() const{
        return capacity;
    }
    void dislayDetails() const{
        cout << "Battery capacity: " << capacity << " mAh" << endl;
    }
}; //end battery calss
class Smartphone{
private:
    string model;
    Battery battery;

public:
    Smartphone(string mod, int batteryCapacity) : model(mod), battery(batteryCapacity){}
    void showDetails() const{
        cout << "Smartphone model: " << model << endl;
        battery.dislayDetails();
    }
};

int main(){
    Smartphone phone1("Samsung", 4000);
    phone1.showDetails();  
    Smartphone phone2("Iphone", 5000);
    phone2.showDetails();
    return 0;
}