#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ifstream file("article.txt");
    
    if (!file) 
	{
        cerr << "error" << endl;
        return 1;
    }
    
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    streampos halfPoint = fileSize / 2;

    file.seekg(halfPoint, ios::beg);

    string dummy;
    getline(file, dummy);

    cout << "preview:\n";
    string line;
    int count = 0;
    while (getline(file, line) && count < 10) 
	{
        cout << line << endl;
        count++;
    }
    file.close();
    return 0;
}