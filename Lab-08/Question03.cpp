/*A C++ developer, utterly fed up with the simplicity of real numbers, decides to shake things up by
creating a ComplexNumber class—because why settle for numbers that behave when you can
have ones with imaginary side effects? But just storing complex numbers isn’t enough—these
numbers need action and operator overloading to truly unleash their potential! First up is addition
(+), where two numbers team up like superheroes—3 + 4i and 1 + 2i join forces to become 4 + 6i.
Then comes subtraction (-), for when numbers need a little personal space—like 8 + 3i kicking 5 +
6i to the curb, leaving behind a 3 - 3i situation. Of course, there's multiplication (*), where two
numbers combine with chaotic consequences—(2 + 3i) * (1 + 4i) suddenly transforms into -10 +
11i, proving that multiplying complex numbers is anything but simple. Finally, there's the equality
check (==), because some numbers are identical (3 + 5i == 3 + 5i), while others are just wannabes
(3 + 5i != 4 + 5i—nice try).*/
#include<iostream>
using namespace std;

class ComplexNumber{
    private:
    int a, b;
    public:
        ComplexNumber(){}
        ComplexNumber(int x, int y): a(x), b(y){}
    ComplexNumber operator + (const ComplexNumber&obj){
        int tempx =a+obj.a;
        int tempy= b+obj.b;
        return ComplexNumber(tempx, tempy);
    }
    ComplexNumber operator - (const ComplexNumber&obj){
        int tempx =a-obj.a;
        int tempy= b-obj.b;
        return ComplexNumber(tempx, tempy);
    }
    ComplexNumber operator * (const ComplexNumber&obj){
        int tempx =a*obj.a-(b*obj.b);
        int tempy= a*obj.b+ (b*obj.a);
        return ComplexNumber(tempx, tempy);
    }
    void show(){
        cout << " " << a << " + " << b << "i" << endl;
    }
    void operator == (ComplexNumber &obj){
        if(a==obj.a && b==obj.b){
            cout<< "Numbers are equal!"<<endl;
        }
        else{
            cout<<"Number are not equal, nice try diddy"<<endl;
        }
    }
};

int main(){
    ComplexNumber obj1(2,4);
    ComplexNumber obj2(1,3);
    ComplexNumber result;
    result=obj1+obj2;
    result.show();
    ComplexNumber obj3(5,6);
    ComplexNumber obj4(2,3);
    result=obj3-obj4;
    result.show();
    ComplexNumber obj5(2,3);
    ComplexNumber obj6(1,4);
    result=obj5*obj6;
    result.show();
    ComplexNumber obj7(1, 1), obj8(1, 1), obj9(2, 2);
    obj7 == obj8;
    obj8 == obj9;
    return 0;
}