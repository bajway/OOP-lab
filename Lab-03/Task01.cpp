/*Design a class named BoardMarker with the following attributes:
 Company (e.g., Dollar)
 Color (e.g., black, red)
 Refillable (Boolean – specifies if the marker can be refilled)
 Ink status (Boolean – indicates whether the ink is empty)
Implement appropriate getters and setters for these attributes. Additionally, include the
following methods:
 write() – This method should check if the ink is empty before allowing writing. If the
ink is empty, display a message indicating that writing is not possible; otherwise,
proceed with writing.
 refill() – This method should verify if the marker is refillable. If it is, refill the ink and
update the ink status; otherwise, display a message stating that the marker cannot be
refilled.
Demonstrate the functionality by creating 3 instances of BoardMarker, setting attribute values,
and calling the methods to test writing and refilling operations for each of the 3 markers.*/
#include <iostream>
#include <string>

using namespace std;

class BoardMarker
{
private:
    string company;
    string color;
    bool isRefillable;
    bool inkStatus;

public:
    
    string getCompany(){
        return company;
    }
    string getColor(){
        return color; 
    }
    bool isRefillableMethod(){ 
        return isRefillable;
    }
    bool isInkEmpty(){ 
        return !inkStatus; 
    }
    void setCompany(const string &comp){
        company = comp;
    }
    void setColor(const string &col){ 
        color = col; 
    }
    void setRefillable(bool refill){ 
        isRefillable = refill; 
    }
    void setInkStatus(bool ink){ 
        inkStatus = ink; 
    }
    void write()
    {
        if (isInkEmpty())
        {
            cout << "Ink is empty. Cannot write.\n";
        }
        else
        {
            cout << "Marker is full, Proceed writing" << endl;
            
        }
    }
    void refill()
    {
        if (isRefillable)
        {
            inkStatus = true;
            cout << "Marker refilled.\n";
        }
        else
        {
            cout << "Marker cannot be refilled.\n";
        }
    }
};

int main()
{
    BoardMarker m1;
    m1.setCompany("Dollar");
    m1.setColor("Black");
    m1.setRefillable(true);
    m1.setInkStatus(true);

    BoardMarker m2;
    m2.setCompany("Dollar");
    m2.setColor("Blue");
    m2.setRefillable(false);
    m2.setInkStatus(false);

    BoardMarker m3;
    m3.setCompany("Dollar");
    m3.setColor("red");
    m3.setRefillable(true);
    m3.setInkStatus(false);
    cout << "Marker 1:\n";
    m1.write();
    m1.setInkStatus(false);
    m1.write();
    m1.refill();
    m1.write();

    cout << "\nMarker 2:\n";
    m2.write();
    m2.refill();
    m2.write();

    cout << "\nMarker 3:\n";
    m3.write();
    m3.refill();
    m3.write();

    return 0;
}

