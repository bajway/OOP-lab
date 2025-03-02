#include <iostream>
#include <string>
using namespace std;

class MenuItem{
private:
    string name;
    double price;

public:
    MenuItem(string itemName = "", double itemPrice = 0.0) : name(itemName), price(itemPrice) {}

    string getName() const{
        return name;
    }

    double getPrice() const{
        return price;
    }

    void display() const{
        cout << name << ": " << price<< " $" << endl;
    }
};

class Menu{
private:
    MenuItem items[50];
    int itemCount;

public:
    Menu() : itemCount(0){}
    void addItem(const MenuItem& item){
        if (itemCount < 50) {
            items[itemCount++] = item;
        } else {
            cout << "Menu is full :(" << endl;
        }
    }

    void removeItem(const string& itemName){
        for (int i = 0; i < itemCount; ++i)
        {
            if (items[i].getName() == itemName)
            {
                for (int j = i; j < itemCount - 1; ++j)
                {
                    items[j] = items[j + 1];
                }
                itemCount--;
                break;
            }
        }
    }

    void displayMenu() const{
        cout << "Menu:" << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            items[i].display();
        }
    }
    const MenuItem* findItem(const string& itemName) const{
        for (int i = 0; i < itemCount; ++i)
        {
            if (items[i].getName() == itemName)
            {
                return &items[i];
            }
        }
        return nullptr;
    }
};

class Payment{
private:
    double amount;

public:
    Payment(double amnt = 0.0) : amount(amnt){}

    double getAmount() const{
        return amount;
    }

    void display() const{
        cout << "Total payment: $" << amount << endl;
    }
};

class Order{
private:
    MenuItem orderedItems[50];
    int itemCount;
    Payment payment;

public:
    Order() : itemCount(0), payment(0.0){}

    void addItem(const MenuItem& item){
        if (itemCount < 50)
        {
            orderedItems[itemCount++] = item;
            payment = Payment(calculateTotal());
        } 
        else 
            cout << "Order is full!" << endl;
    }

    double calculateTotal() const{
        double total = 0;
        for (int i = 0; i < itemCount; ++i)
        {
            total += orderedItems[i].getPrice();
        }
        return total;
    }

    void displayOrder() const{
        cout << "Order details:" << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            orderedItems[i].display();
        }
        payment.display();
    }
};

int main(){
    Menu menu;
    menu.addItem(MenuItem("Burger", 5.99));
    menu.addItem(MenuItem("Pizza", 8.99));
    menu.addItem(MenuItem("BBQ", 4.99));
    menu.displayMenu();
    Order order;
    const MenuItem* item = menu.findItem("Pizza");
    if (item)
        order.addItem(*item);
    item = menu.findItem("Salad");
    if (item)
        order.addItem(*item);
    order.displayOrder();
    return 0;
}