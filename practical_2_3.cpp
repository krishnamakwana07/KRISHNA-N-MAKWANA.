#include <iostream>
#include <limits>
using namespace std;

class Account {
private:
    string name;
    int accID;
    double balance;

public:
    // Default constructor
    Account() {
        name = "Default";
        accID = 0;
        balance = 0;
    }

    // Parameterized constructor
    Account(string n, int id, double bal) {
        name = n;
        accID = id;
        balance = bal;
    }

    // Getter for Account ID
    int getID() {
        return accID;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        } 
        else if (amount > balance) {
            cout << "Insufficient balance! Withdrawal denied.\n";
        } 
        else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    // Display function
    void display() {
        cout << "Account ID: " << accID
             << ", Name: " << name
             << ", Balance: " << balance << endl;
    }
};

// Global storage
Account acc[100];
int countAcc = 0;

// Function to create account
void createAccount() {
    if (countAcc >= 100) {
        cout << "Maximum accounts reached!\n";
        return;
    }

    int choice;
    cout << "\n1. Zero Balance Account\n2. Custom Balance Account\nEnter choice: ";
    cin >> choice;

    string name;
    int id;
    double bal = 0;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Account ID: ";
    cin >> id;

    if (choice == 2) {
        cout << "Enter Initial Balance: ";
        cin >> bal;
    }

    acc[countAcc] = Account(name, id, bal);
    countAcc++;

    cout << "Account created successfully!\n";
}

// Function to find account by ID
int findAccount(int id) {
    for (int i = 0; i < countAcc; i++) {
        if (acc[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n--- Digital Savings Account System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Display All Accounts\n5. Exit\nEnter choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (choice == 1) {
            createAccount();
        }

        else if (choice == 2) {
            int id;
            double amt;

            cout << "Enter Account ID: ";
            cin >> id;

            int index = findAccount(id);

            if (index == -1) {
                cout << "Account not found!\n";
                continue;
            }

            cout << "Enter amount to deposit: ";
            cin >> amt;

            acc[index].deposit(amt);
        }

        else if (choice == 3) {
            int id;
            double amt;

            cout << "Enter Account ID: ";
            cin >> id;

            int index = findAccount(id);

            if (index == -1) {
                cout << "Account not found!\n";
                continue;
            }

            cout << "Enter amount to withdraw: ";
            cin >> amt;

            acc[index].withdraw(amt);
        }

        else if (choice == 4) {
            if (countAcc == 0) {
                cout << "No accounts available!\n";
            } else {
                for (int i = 0; i < countAcc; i++) {
                    acc[i].display();
                }
            }
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}