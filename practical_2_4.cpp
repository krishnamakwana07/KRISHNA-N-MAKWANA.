#include <iostream>
using namespace std;

// Class for Item
class Item {
private:
    int itemID;
    string name;
    float price;
    int quantity;

public:
    // Default constructor
    Item() {
        itemID = 0;
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int id, string n, float p, int q) {
        itemID = id;
        name = n;
        price = p;
        quantity = q;
    }

    // Function to add stock
    void addStock(int amount) {
        quantity += amount;
        cout << "Stock added successfully!\n";
    }

    // Function to sell item
    void sellItem(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
            cout << "Item sold successfully!\n";
        } else {
            cout << "Not enough stock available!\n";
        }
    }

    // Function to display item details
    void display() {
        cout << "\nItem ID: " << itemID;
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    // Array of objects
    Item items[100];

    // Input item details
    for (int i = 0; i < n; i++) {
        int id, qty;
        string name;
        float price;

        cout << "\nEnter details for item " << i + 1 << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty); // parameterized constructor
    }

    int choice, index, amount;

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Add Stock";
        cout << "\n2. Sell Item";
        cout << "\n3. Display All Items";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item index: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;
            items[index].addStock(amount);
            break;

        case 2:
            cout << "Enter item index: ";
            cin >> index;
            cout << "Enter amount to sell: ";
            cin >> amount;
            items[index].sellItem(amount);
            break;

        case 3:
            for (int i = 0; i < n; i++) {
                items[i].display();
            }
            break;

        case 4:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}