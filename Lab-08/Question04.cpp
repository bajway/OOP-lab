/*Traffic jams are the ultimate test of patience, but what if C++ could take control of the chaos?
Enter the TrafficSystem class, designed to bring order to the madness using operator overloading.
First up is addition (+), because when more cars enter a busy intersection (50 cars + 20 more), the
total count surges to 70, making the situation even worse. Then comes subtraction (-), offering a
glimmer of hope—if 15 cars finally move out, the congestion eases to 55, though not for long!
Next, there’s multiplication (*), useful for scenarios like a traffic signal failure doubling the wait
time—if the delay was 5 minutes, it instantly jumps to 10 minutes, leaving drivers questioning all
their life choices. And finally, there's equality (==), critical for detecting traffic gridlocks—when
road A and road B both have 100 cars stuck motionless, it’s official: the city is doomed! Your
mission? Write a TrafficSystem class in C++ that smartly handles all these scenarios with operator
overloading,*/

#include<iostream>
using namespace std;

class TrafficSystem{
    private:
        int count;
    public:
    TrafficSystem(){}
    TrafficSystem(int c): count(c){}
    int getCount(){
        return count;
    }
    TrafficSystem operator +(const TrafficSystem &obj){
        return TrafficSystem(count + obj.count);
    }
    TrafficSystem operator -(const TrafficSystem& obj){
        return TrafficSystem(count - obj.count);

    }
    TrafficSystem operator *(int times){
        int temp = count * times;
        return TrafficSystem(temp);
    }
    bool operator==(const TrafficSystem& obj){
        if(count==obj.count)
            return true;
        else
            return false;
    }
    void display(){
        cout << "Number of cars: " << count << endl;
        
    }
    
};


int main(){
    TrafficSystem start(50);
    TrafficSystem add(20);
    TrafficSystem total = start + add;
    total.display();
    TrafficSystem exit(15);
    TrafficSystem left = total - exit;
    total.display();
    TrafficSystem timeDelay(5);
    TrafficSystem updateTime = timeDelay * 2;
    bool isLock = (start == add);
    return 0;
}