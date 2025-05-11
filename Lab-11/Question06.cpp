#include <iostream>
#include <string>
using namespace std ;
class InvalidAgeException 
{
    public:
        string exception ;
        InvalidAgeException(string exception) : exception(exception) {}
} ;
class InvalidSalaryException 
{
    public:
        string exception ;
        InvalidSalaryException(string exception) : exception(exception) {}
} ;
class InvalidHeightException 
{
    public:
        string exception ;
        InvalidHeightException(string exception) : exception(exception) {}
} ;
int main() 
{
    int age , salary , height ;
    try 
    {
        cout<<"Enter age:" ;
        cin>>age ;
        if(age<=0 || age>=120) 
        {
            throw InvalidAgeException("Age must be between 1 and 119") ;
        }
        cout<<"Enter salary:" ;
        cin>>salary ;
        if(salary<=0) 
        {
            throw InvalidSalaryException("Salary must be positive") ;
        }
        cout<<"Enter height:" ;
        cin>>height ;
        if(height<=0) 
        {
            throw InvalidHeightException("Height must be positive") ;
        }
    }
    catch(const InvalidAgeException& e) 
    {
        cout<<"InvalidAgeException caught:" <<e.exception<<endl ;
    }
    catch(const InvalidSalaryException& e) 
    {
        cout<<"InvalidSalaryException caught:" <<e.exception<<endl ;
    }
    catch(const InvalidHeightException& e) {
        cout<<"InvalidHeightException caught:" <<e.exception<<endl ;
    }
    return 0 ;
}