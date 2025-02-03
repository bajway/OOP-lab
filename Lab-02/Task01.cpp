/*Imagine you are tasked with creating a program to manage a library's book inventory. Each
book has attributes such as title, author, publication year, and genre. Design a struct that
effectively represents a book as a real-world entity. Then, write a C++ program that utilizes
this struct to demonstrate the creation, modification, and display of book information.
a) Extend the program to manage multiple books in an array.
b) Implement a function to search for a book by title or author.
c) Allow the user to input new books and update existing book information
interactively.*/

#include <iostream>
#include <string>
#define maxBooks 50
using namespace std;

struct Book {
    string title;
    string author;
    int pubYear;
    string genre;
};

bool searchBook(string title, string author, Book books[], int tBooks) {
    for (int i = 0; i < tBooks; i++) {
        if (books[i].title == title || books[i].author == author) {
            cout << "Book Found!!" << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Publication Year: " << books[i].pubYear << endl;
            cout << "Genre: " << books[i].genre << endl;
            return true;
        }
    }
    cout << "Book Not Found! " << endl;
    return false;
}

int main() {
    int choice, tBooks = 0, booksCount = 0;
    Book books[maxBooks];
    cout << "* * * * * * * * * * LIBRARY'S BOOK INVENTORY SYSTEM * * * * * * * * * * " << endl << endl;

    do {
        cout << "1. Add a book" << endl;
        cout << "2. Update existing book information" << endl;
        cout << "3. Search a book" << endl;
        cout << "4. Exit the program" << endl;
        cout << endl;
        cout << "Please select from the menu to proceed further: " << endl;
        cin >> choice;
        cin.ignore(); //to clear buffer

        if (choice == 1) {
            cout << "Enter the number of books you want to add: " << endl;
            cin >> tBooks;
            cin.ignore(); 
            for (int i = booksCount; i < booksCount + tBooks; i++) {
                cout << "Enter the title of Book " << i + 1 << ":" << endl;
                getline(cin, books[i].title);
                cout << "Enter the author of Book " << i + 1 << ":" << endl;
                getline(cin, books[i].author);
                cout << "Enter the Publication Year of Book " << i + 1 << ":" << endl;
                cin >> books[i].pubYear;
                cin.ignore(); 
                cout << "Enter the genre of Book " << i + 1 << ":" << endl;
                getline(cin, books[i].genre);
            }
            booksCount += tBooks;
        } else if (choice == 2) {
            string title;
            cout << "Enter the Book title to search: ";
            getline(cin, title);
            bool found = false;
            for (int i = 0; i < booksCount; i++) {
                if (books[i].title == title) {
                    found = true;
                    cout << "Book Found" << endl;
                    cout << "1. Update Title" << endl;
                    cout << "2. Update Author" << endl;
                    cout << "3. Update Publication Year" << endl;
                    cout << "4. Update Genre" << endl;
                    cout << "5. Return to main menu" << endl;
                    cout << endl;
                    cout << "Please select from the menu to proceed further: " << endl;
                    int updateChoice;
                    cin >> updateChoice;
                    cin.ignore(); 
                    if (updateChoice == 1) {
                        cout << "Enter the Updated title: ";
                        getline(cin, books[i].title);
                    } else if (updateChoice == 2) {
                        cout << "Enter the updated name of author: ";
                        getline(cin, books[i].author);
                    } else if (updateChoice == 3) {
                        cout << "Enter the updated publication Year: ";
                        cin >> books[i].pubYear;
                        cin.ignore(); //clearing Buffer
                    } else if (updateChoice == 4) {
                        cout << "Enter the updated genre: ";
                        getline(cin, books[i].genre);
                    } else if (updateChoice == 5) {
                        cout << "Returning to Main Menu..." << endl;
                    } else {
                        cout << "Invalid Command" << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Book Not Found in Record" << endl;
            }
        } else if (choice == 3) {
            string author, title;
            cout << "Enter the title of book: ";
            getline(cin, title);
            cout << "Enter the author of book: ";
            getline(cin, author);
            searchBook(title, author, books, booksCount);
        } else if (choice == 4) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid Command" << endl;
        }
    } while (choice != 4);

    return 0;
}


