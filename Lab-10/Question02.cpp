#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    string entries;
    ofstream write("diary.txt");
    cout << "Enter the data (exit to stop)" << endl;
    while (true)
    {
        getline(cin, entries);
        if (entries != "exit")
        {

            write << entries << endl;
        }
        else
            break;
    }
    return 0;
}