#include<iostream>
using namespace std;

template <typename T1, typename T2>
class Pair{
    T1 value1;
    T2 value2;
    public:
    Pair(T1 val1, T2 val2): value1(val1), value2(val2){}
    void display(){
        cout << "Pair: (" << value1 << ", " << value2 << ")" << endl;
    }
};
int main(){
    Pair<int, string> v1(5, "Hello");
    v1.display();
    Pair<double, int> v2(3.142, 42);
    v2.display();
    return 0;
}