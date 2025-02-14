#include<iostream>
#include<string>
using namespace std;
class Book{
    public:
    string title;
    string author;
    double price;
    Book(){
        title="Untitled";
        author="Anonymous";
        price=0.0;
    }
    //Parameterized constructor
    Book(string title, string author, double price){
        this->title=title;
        this->author=author;
        this->price=price;
    }
//Shallow copy constructor
    Book(Book& obj){
        title=obj.title;
        author=obj.author;
        price=obj.price;
    }
    void display(){
        cout<< title << endl;
        cout<< author << endl;
        cout<< price << endl;
        cout<< endl;
    }

};
int main(){
    Book b1;
    Book b2("Factfullness", "James Bond", 100.0);
    Book b3("Rich Dad Poor Dad", "James", 80.0);
    Book b4;
    b4=b3;
    b1.display();
    b2.display();
	b3.display();
	b4.display();
    return 0;
}
