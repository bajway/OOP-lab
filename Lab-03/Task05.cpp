#include <iostream>
#include <string>
using namespace std;
class Employee 
{
private:
    string name;
    double salary, tax;
public:
    Employee() : name(""), salary(0.0), tax(2.0) {}
    void getter_for_data()
        {   cout<<"input employee name: ";
            cin>> name;
            cout<<"input monthly salary: ";
            cin>>salary;
            cout<<"input tax percentage: ";
            cin>>tax;
        }
    double salary_with_taxation() 
        {  returnsalary*(1-tax/100);
        }
    double update_percentage(double newsalary) 
        {   tax=newsalary;
            return salary_with_taxation();
        }
};
int main() 
{   Employee e1;
    e1.getter_for_data();
    cout <<"salary after tax is applied:"<< e1.salary_with_taxation()<<endl;
    double newsalary;
    cout << "input new tax percentage:";
    cin >> newsalary;
    cout <<"updated salary:"<<e1.update_percentage(newsalary)<<endl;
    return 0;
}
