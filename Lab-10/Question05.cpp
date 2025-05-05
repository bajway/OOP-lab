#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile("story.txt");

    if (!inputFile.is_open())
    {
        cerr << "error" << endl;
        return 1;
    }
    string paragraph;
    getline(inputFile, paragraph);
    istringstream iss(paragraph); 
    string word;
    while (iss >> word)
    {
        cout << word << endl;
    }
    inputFile.close();
    return 0;
}