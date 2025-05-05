#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    fstream file("draft.txt", ios::in | ios::out);
    
    if (!file) 
	{
        cerr << "Error opening draft.txt" << endl;
        return 1;
    }

    string word;
    streampos position;
    char ch;
    bool found = false;

    while (file.get(ch)) 
	{
    	
        position = file.tellg();
        if (ch == 't') 
		{
            char buffer[3];
            buffer[0] = ch;
            file.get(buffer[1]);
            file.get(buffer[2]);

            if (buffer[1] == 'e' && buffer[2] == 'h') 
			{
                file.seekp(position);
                file.write("the", 3);
                found = true;
                break;
            } 
			else 
			{
                file.seekg(position);
            }
        }
    }

    file.close();

    if (found)
        cout << "Correct";
    else
        cout << "'teh' not found ";

    return 0;
}