#include <iostream>
#include <string>

using namespace std;

class Airport {
private:
    string name;
    string location;

public:
    Airport(string airportName, string airportLocation) : name(airportName), location(airportLocation){}

    string getName() const{
        return name;
    }
    string getLocation() const{
        return location;
    }
    void display() const{
        cout << "Airport: " << name << ", Location: " << location << endl;
    }
};

class Flight {
private:
    string flightNumber;
    Airport* departure;
    Airport* destination;
    Airport* currentLocation;

public:
    Flight(string number, Airport* dep, Airport* dest) : flightNumber(number), departure(dep), destination(dest), currentLocation(dep){}

    void land(Airport* newLocation){
        currentLocation = newLocation;
        cout << "Flight " << flightNumber << " has landed at " << currentLocation->getName() << endl;
    }

    void takeOff(){
        cout << "Flight " << flightNumber << " is taking off from " << currentLocation->getName() << endl;
    }

    void display() const{
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Departure: " << departure->getName() << endl;
        cout << "Destination: " << destination->getName() << endl;
        cout << "Current Location: " << currentLocation->getName() << endl;
    }
};

int main(){
    Airport karachi("Jinnah International Airport", "Karachi");
    Airport islamabad("Islamabad International Airport", "Islamabad");
    Airport london("Heathrow Airport", "London");
    Flight pk303("PK-303", &karachi, &london);
    pk303.display();
    pk303.takeOff();
    pk303.land(&islamabad);
    pk303.display();

    return 0;
}