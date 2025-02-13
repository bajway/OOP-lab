/*Create a Circle class with the following member variables: radius, a double representing the
circle’s radius, and pi, a double initialized with the value 3.14159. The class should include
the following member functions: setRadius(), a mutator function to set the radius; getRadius(),
an accessor function to retrieve the radius; getArea(), which returns the area of the circle using
the formula area = pi * radius * radius; getDiameter(), which calculates and returns the
diameter using diameter = radius * 2; and getCircumference(), which calculates and returns
the circumference using circumference = 2 * pi * radius. Write a program that demonstrates
the Circle class by prompting the user to input a radius, creating a Circle object, and displaying
the calculated area, diameter, and circumference.
*/
#include<iostream>
using namespace std;

class Circle{
    private:
    double radius;
    double pi = 3.142;
    public:
    void setRadius(double r){
        radius = r;
    }
    double getRadius(){
        return radius;
    }
    double getArea(){
        double area;
        area = pi * radius * radius;
        return area;
    }
    double getDiameter(){
        double diameter = radius * 2;
        return diameter;
    }
    double getCircumference(){
        double circumference = 2 * pi * radius;
        return circumference;
    }
};
int main()
{
    Circle c1;
    double rad, Area, Diameter, Circumference;
    cout << "Enter the radius: ";
    cin >> rad;
    c1.setRadius(rad);
    Area = c1.getArea();
    Diameter = c1.getDiameter();
    Circumference = c1.getCircumference();
    cout << "Area: " << Area << endl;
    cout << "Diameter: " << Diameter << endl;
    cout << "Circumference: " << Circumference << endl;
    return 0;
}