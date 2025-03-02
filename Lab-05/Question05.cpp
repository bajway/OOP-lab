#include <iostream>
#include <string>

using namespace std;

class ValidateString{
private:
    string str;

public:
    ValidateString(const string& input) : str(input){}
    //function is set to be const so that it can not modify the string that is input by user
    bool isValid() const{
        for (char ch : str)
        {
            if (!isalpha(ch))//funtion to check if the current character is aplhabet or not
            {
                return false;
            }
        }
        return true;
    }

    void displayValidation() const{
        if (isValid()) 
            cout << "The string \"" << str << "\" is Valid" << endl;
        else 
            cout << "The string \"" << str << "\" is Invalid " << endl;
        
    }
};

int main(){
    ValidateString str1("Hello Wor!d");
    str1.displayValidation();  
    ValidateString str2("Kashif_691");
    str2.displayValidation();  
    ValidateString str3("MyComputer");
    str3.displayValidation();  
    return 0;
}