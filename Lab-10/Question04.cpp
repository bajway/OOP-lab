#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void logSystemStartup()
{
    ofstream logFile("system_log.txt", ios::app);

    if (!logFile.is_open())
    {
        cerr << "errror" << endl;
        return;
    }
    //time part from github repo
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", localTime); 
    logFile << "system started; " << timeStr << endl;
    logFile.close();
}

int main()
{
    logSystemStartup();
    return 0;
}