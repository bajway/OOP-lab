/*Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.*/
#include <iostream>
using namespace std;

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() const = 0;
};

class LightBulb : public SmartDevice
{
private:
    bool isOn;
    int brightness;

public:
    LightBulb(bool stat, int b) : isOn(stat), brightness(b) {}
    void turnOn() override
    {
        isOn = true;
        cout << "Light Bulb turned On Brightness level " << brightness << "%" << endl;
    }
    void turnOff() override
    {
        isOn = false;
        cout << "Light Bulb turned Off" << endl;
    }
    bool getStatus() const override
    {
        return isOn;
    }
};
class Thermostat : public SmartDevice
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat(bool stat, double temp): isOn(stat), temperature(temp){}
    void turnOn() override
    {
        isOn = true;
        cout << "Thermostat turned On, temperature: " <<temperature<< endl;
    }
    void turnOff() override
    {
        isOn = false;
        cout << "Thermostat turned Off" << endl;
    }
    bool getStatus() const override
    {
        return isOn;
    }
};
int main(){
    LightBulb bulb(false, 72);
    Thermostat t(true, 45);
    bulb.turnOn();
    bulb.turnOff();
    cout << "Bulb Status : " << (bulb.getStatus() ? "On" : "Off") << endl;
    t.turnOn();
    t.turnOff();
    cout << "Thermostat Status : " << (t.getStatus() ? "On" : "Off") << endl;
    return 0;
}