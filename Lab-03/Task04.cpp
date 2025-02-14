#include <iostream>
#include <string>
using namespace std;
class StationeryShop {
private:
    string items[100];
    double prices[100];
    int count;
public:
    StationeryShop() : count(0) {}
    void adding_items() 
    { if (count >= 100) 
          {   cout << "Out of storage!\n";
              return;
          }
        cout << "Item name: ";
        cin >> items[count];
        cout << "Item price: ";
        cin >> prices[count++];
    }

    void display_items() const 
    { if (count == 0) 
        {   cout << "No items available.\n";
            return;
        }
        for (int i = 0; i < count; i++)
            cout <<"Price of " items[i] << " is " << prices[i] << endl;
    }

    void editing_cost() 
    {   int no;
        cout << "Enter item number to edit price: ";
        cin >> no;
        if (no > 0 && no <= count) 
        {   cout << "New price: ";
            cin >> prices[no - 1];
        } else 
        { cout << "Invalid item number!\n";
        }
    }

    void making_receipt() const 
    {    if (count == 0) 
        {   cout << "No item avaialable";
            return;
        }
        double t = 0;
        int num;
        for (int i = 0; i < count; i++) 
        {   cout << "Quantity for " << items[i] << ": ";
            cin >> num;
            if (quantity > 0) 
            {   t += prices[i] * num;
                cout << items[i] << " x " << num << " = Rs " << prices[i] * num << endl;
            }
        }
        cout << "Total: Rs " << t << endl;
    }
};

int main() {
    StationeryShop s;
    int option;
    do 
    {   cout << "\n1. Add\n2. Display\n3. Edit\n4. Receipt\n5. Exit\nOption: ";
        cin >> option;
        switch (option) 
        {   case 1: s.adding_items(); break;
            case 2: s.display_items(); break;
            case 3: s.editing_cost(); break;
            case 4: s.making_receipt(); break;
            case 5: break;
            default: cout << "invalid option!\n";
        }
    }while (option != 5);
    return 0;
}
