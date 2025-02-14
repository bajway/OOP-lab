#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee 
{
private:
    string name;
    double salary,taxrate;
public:
    Employee();  
    void input_Details();
    double calculate_net_Salary() const;
    void set_tax_Rate(double newRate);
};
#endif
