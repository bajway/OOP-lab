#include <iostream>
#include <string>
using namespace std;

class Media {
public:
    string mediaTitle, releaseDate, mediaID, publisherName;
    bool isCheckedOut = false;

    Media(string title, string date, string id, string publisher) 
        : mediaTitle(title), releaseDate(date), mediaID(id), publisherName(publisher) {}

    virtual void showDetails() 
    {
        cout << "Title: " << mediaTitle << endl 
             << "Publication Date: " << releaseDate << endl 
             << "ID: " << mediaID << endl 
             << "Publisher: " << publisherName << endl;
    }

    void borrowItem() 
    {
        if (isCheckedOut) 
            cout << "Already borrowed!";
        else 
        {
            isCheckedOut = true;
            cout << "Borrowed successfully!";
        }
    }

    void returnItem() 
    {
        if (!isCheckedOut) 
            cout << "Already in the library.";
        else 
        {
            isCheckedOut = false;
            cout << "Returned successfully.";
        }
    }
};

class Book : public Media 
{
public:
    string authorName, bookISBN;
    int totalPages;

    Book(string title, string date, string id, string publisher, string author, string isbn, int pages) 
        : Media(title, date, id, publisher), authorName(author), bookISBN(isbn), totalPages(pages) {}

    void showDetails() override 
    {
        Media::showDetails();
        cout << "Author: " << authorName << endl 
             << "ISBN: " << bookISBN << endl 
             << "Total Pages: " << totalPages << endl;
    }
};

class DVD : public Media 
{
public:
    string directorName, rating;
    double duration;

    DVD(string title, string date, string id, string publisher, string director, double time, string rate) 
        : Media(title, date, id, publisher), directorName(director), duration(time), rating(rate) {}

    void showDetails() override 
    {
        Media::showDetails();
        cout << "Director: " << directorName << endl 
             << "Duration: " << duration << " hours" << endl 
             << "Rating: " << rating << endl;
    }
};

class CD : public Media 
{
public:
    string artistName, musicGenre;
    int trackCount;

    CD(string title, string date, string id, string publisher, string artist, int tracks, string genre) 
        : Media(title, date, id, publisher), artistName(artist), trackCount(tracks), musicGenre(genre) {}

    void showDetails() override 
    {
        Media::showDetails();
        cout << "Artist: " << artistName << endl 
             << "Tracks: " << trackCount << endl 
             << "Genre: " << musicGenre << endl;
    }
};

class Magazine : public Media 
{
public:
    int totalPages;

    Magazine(string title, string date, string id, string publisher, int pages) 
        : Media(title, date, id, publisher), totalPages(pages) {}

    void showDetails() override 
    {
        Media::showDetails();
        cout << "Total Pages: " << totalPages << endl;
    }
};

class Library {
public:
    Media* collection[100];
    int itemCount = 0;

    void addMedia(Media* mediaItem) 
    {
        if (itemCount < 100) 
            collection[itemCount++] = mediaItem;
        else 
            cout << "Library is full!";
    }

    void findByTitle(string title) 
    {
        for (int i = 0; i < itemCount; i++) 
        {
            if (collection[i]->mediaTitle == title) 
            {
                cout << "Item found!" << endl;
                collection[i]->showDetails();
                return;
            }
        }
        cout << "Item not found!";
    }

    void findByYear(int year) 
    {
        bool found = false;
        for (int i = 0; i < itemCount; i++) 
        {
            if (collection[i]->releaseDate == to_string(year))
            {
                cout << "Item found:\n";
                collection[i]->showDetails();
                found = true;
            }
        }
        if (!found)
            cout << "No items found for the year " << year << ".\n";
    }
};

int main() 
{
    Library myLibrary;
    Book book1("The art of talking", "2002", "K2539", "NY publishers", "James Williamson", "9781612680194", 256);
    myLibrary.addMedia(&book1);  
    book1.showDetails();
    return 0;
}
