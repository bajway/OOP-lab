#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    string log;
    ofstream logFile("backup_log.txt", ios::app); 

    if (!logFile) 
	{
        cerr << "error" << endl;
        return 1;
    }

    cout << "Enter log messages (type 'exit' to quit):\n";

    while (true) 
	{
        cout << "enter: " << endl;
        getline(cin, log);

        if (log == "exit") 
			break;

        logFile << log << endl;

        streampos size = logFile.tellp();
        cout << "file size: " << size;
    }

    logFile.close();
    return 0;
}