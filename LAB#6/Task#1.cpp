/* You're designing a library system in C++, but this isn't just any boring old database—this is where
books come to life (well, sort of). First, you need a Book class because, let’s be honest, a library
without books is just a fancy warehouse. This class will hold the VIP details: title, author, and
publisher—the holy trinity of bookish existence. Of course, like any respectable book, it needs a
constructor to bring it into the world and a display function to proudly announce, "Hey, look at me!
I exist!" But hold onto your bookmarks, because here comes the real page-turner! You need a
FictionBook class that inherits from Book—because let’s face it, fiction books are the fun ones!
This subclass adds genre (so we know if it's a thrilling mystery or a sappy romance) and protagonist
(because every story needs a hero—or an anti-hero if you’re feeling dramatic). This class will also
have a constructor to set everything up and a display function to spill all the juicy details. Finally,
in the main function, you’ll create an object of FictionBook and display its details, because what’s
the point of writing code if you can’t flex it? So, grab your imaginary reading glasses, and let’s turn
this coding project into a bestseller! */

#include <iostream>
#include <string>

using namespace std;
class Book {
protected:
    string bookTitle;
    string bookAuthor;
    string bookPublisher;
public:
    Book(string title, string author, string publisher) : bookTitle(title), bookAuthor(author), bookPublisher(publisher) {}
    void display() {
        cout << "Title: " << bookTitle << endl << "Author: " << bookAuthor << endl << "Publisher: " << bookPublisher << endl; }
};
class FictionBook : public Book {
private:
    string bookGenre;
    string mainCharacter;
public:
    FictionBook(string title, string author, string publisher, string genre, string protagonist): Book(title, author, publisher), bookGenre(genre), mainCharacter(protagonist) {}
    void display() {
        Book::display();
        cout << "Genre: " << bookGenre << endl << "Main Character: " << mainCharacter << endl; }
};

int main() {
    FictionBook adventureBook("Crimson Vengeance", "Jaxon Kane", "Titan Edge Publishing", "Action  Thrille", "Logan Pierce");
    adventureBook.display();
    return 0;
}
