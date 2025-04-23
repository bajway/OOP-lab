/*Problem: A public library is transitioning from manual record-keeping to a digital system.
Staff need secure access to book details (title, author, ISBN) but must not modify records
directly. The system should separate public interfaces (e.g., searching books) from internal
data handling to prevent accidental data corruption.
Classes and Structure:
• Class Book (Header: Book.h, Implementation: Book.cpp):
o Data Members:
▪ title, author, ISBN (strings): Store book metadata.
o Member Functions:
▪ Constructor to initialize book details.
▪ getTitle(), getAuthor(), getISBN(): Return book properties.

• Class Library (Optional for advanced students):
o Data Members:
▪ A collection (e.g., array/list) of Book objects.
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.

Flow:
• Define Book in header and source files to separate interface and implementation.
• In main(), create a Book object and display its metadata.*/
#include <iostream>
using namespace std;
#include "Question03.h"
Book::Book(const string &title, const string &author, const string &ISBN) : title(title), author(author), ISBN(ISBN) {}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return ISBN;
}
int main()
{
    Book book1("2001", "C++ - A beginer's guide to coding", "123-01234451");
    cout << "Book Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;

    return 0;
}
