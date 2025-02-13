/*Create a class called water bottle. The water bottle has a company (made by), color and water
capacity. The water capacity isstored in both liters(l) and milliliters(ml). Create variables and
methods for your class. Methods should include getters and setters. Also create an additional
method that updates the water capacity (both in l and ml) after asking user how much water a
person has drank. Assume that the user always enters the amount in ml. Demonstrate the
functionality of the water bottle in your main method.*/
#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    double waterCapacityL;
    int waterCapacityMl;

public:
    
    string getCompany(){ 
        return company; 
    }
    string getColor(){ 
        return color; 
    }
    double getWaterCapacityL(){ 
        return waterCapacityL;
    }
    int getWaterCapacityMl(){ 
        return waterCapacityMl; 
    }

    void setCompany(const string &comp){ 
        company = comp; 
    }
    void setColor(const string &col){ 
        color = col; 
    }
    void setWaterCapacityL(double capacityL){ 
        waterCapacityL = capacityL; 
        waterCapacityMl = static_cast<int>(capacityL * 1000);
    }
    void setWaterCapacityMl(int capacityMl){ 
        waterCapacityMl = capacityMl; 
        waterCapacityL = capacityMl / 1000.0; 
    }
    void drinkWater(int amountinMl){
        if (amountinMl > waterCapacityMl)
        {
            cout << "Not enough water to drink " << amountinMl << "ml. Drink capacity increased \n";
            waterCapacityL = 0;
            waterCapacityMl = 0;
        } 
        else{
            waterCapacityMl -= amountinMl;
            waterCapacityL = waterCapacityMl / 1000.0;
            cout << "After Drinking " << amountinMl << "ml of water. Remaining capacity is: " << waterCapacityMl << "ml (" << waterCapacityL << "L).\n";
        }
    }
};

int main() {
    WaterBottle b;
    b.setCompany("WaterWays");
    b.setColor("Pink");
    b.setWaterCapacityL(1.5); //litres
    cout << "Water Bottle:\n";
    cout << "Company: " << b.getCompany() << "\n";
    cout << "Color: " << b.getColor() << "\n";
    cout << "Capacity: " << b.getWaterCapacityL() << "L (" << b.getWaterCapacityMl() << "ml)\n";
    b.drinkWater(250); 
    b.drinkWater(500); 
    b.drinkWater(800); 

    return 0;
}
