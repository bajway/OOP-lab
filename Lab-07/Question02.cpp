#include<iostream>
#include<cmath>
using namespace std;

class Shape{
    protected:
        int x, y; // for position
        string color;
        float borderThickness;
    public:
        Shape(int x, int y, string colr, float thickness = 1.0) : x(x), y(y), color(colr), borderThickness(thickness){}

        virtual void draw() const = 0;
        virtual double calculateArea() const = 0;
        virtual double calculateParameter() const = 0;

        virtual ~Shape(); //destructor
};

class Circle: public Shape{
    private:
        float radius;
    public:
        Circle(int x, int y, string colr, float thickness = 1.0, float r) : Shape(x,y,color, borderThickness), radius(r){}
    void draw() const override{
        cout << "Circle having radius: " << radius << " Drawn  at (" << x << "," << y << ")" << endl;
    }
    double calculateArea() const override{
        return M_PI * radius * radius; //area= pi*r^2
    }
    double calculateParameter() const override{
        return 2 * M_PI * radius; // s= 2pi*r
    }

};

class Rectangle : public Shape{
    private:
        float width, height;
    public:
        Rectangle(int x, int y, string color, float width, float height, float borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), width(width), height(height){}
    
        void draw() const override{
            cout << "Rectangle having width " << width << " and height " << height << " drawn at (" << x << "," << y << ")" << endl;
        }
    
        double calculateArea() const override{
            return width * height;
        }
    
        double calculateParameter() const override{
            return 2 * (width + height);
        }
};

class Triangle : public Shape{
    private:
       float side1, side2, side3;    
    public:
        Triangle(int x, int y, string color, float s1, float s2, float s3, float borderThickness = 1.0)
            : Shape(x, y, color, borderThickness), side1(s1), side2(s2), side3(s3){}
        void draw() const override{
            cout << "Drawing Triangle with sides " << side1 << ", " << side2 << ", " << side3 << endl;
        }
        double calculateParameter() const override{
            return side1 + side2 + side3;
        }
        double calculateArea() const override{
            double s = calculateParameter() / 2;
            return sqrt(s * (s - side1) * (s - side2) * (s - side3));
        }
};

int main(){
        Circle c1(5, 5, "Red", 10);
        Rectangle r1(2, 3, "Blue", 4, 6);
        Triangle t1(0, 0, "Green", 3, 4, 5);
    
        c1.draw();
        cout << "Circle Area: " << c1.calculateArea() << ", Perimeter: " << c1.calculateParameter() << endl;
    
        r1.draw();
        cout << "Rectangle Area: " << r1.calculateArea() << ", Perimeter: " << r1.calculateParameter() << endl;
    
        t1.draw();
        cout << "Triangle Area: " << t1.calculateArea() << ", Perimeter: " << t1.calculateParameter() << endl;
    
        return 0;
    }

        
    