#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() 
{
    ifstream inFile("article.txt");
    
    if (!inFile) 
	{
        cerr << "error opening" << endl;
        return 1;
    }

    int charcount = 0, letterword = 0, linecount = 0, markcount = 0;
    string line;

    while (getline(inFile, line)) 
	{
        linecount++;
        charcount += line.length() + 1;

        bool inWord = false;
        for (char ch : line) 
		{
            if (ispunct(ch)) markcount++;

            if (isspace(ch)) 
			{
                if (inWord) 
				{
                    letterword++;
                    inWord = false;
                }
            } else 
			{
                inWord = true;
            }
        }

        if (inWord) letterword++; 
    }

    inFile.close();

    ofstream report("report.txt");
    if (!report) 
	{
        cerr << "error creating" << endl;
        return 1;
    }

    cout << "Total number of Characters : " << charcount << endl;
    cout << "Total number of Words : " << letterword << endl;
    cout << "Total number of Lines : " << linecount << endl;
    cout << "punctuation marks count : " << markcount << endl;

    report.close();
    cout << "Report updated successfully";

    return 0;
}