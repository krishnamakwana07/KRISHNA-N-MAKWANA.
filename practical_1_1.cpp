/*A digital payment company wants to develop a simple account management module for its
users. Each user maintains a digital wallet that allows loading money, transferring money to
another user, and checking the current wallet balance.
Each wallet has:
 A unique wallet ID
 User name
 Current balance
The system should allow:
 Loading money into the wallet
 Transferring money to another wallet only if sufficient balance exists
 Displaying wallet details on request
If transfer amount exceeds the current balance, the system should show an appropriate error
message. The solution must be implemented using Object-Oriented Programming
principles, especially encapsulation and data hiding.*/


#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    string walletID;
    string userName;
    double balance;

public:
    // Constructor
    Wallet(string id, string name, double initial_Balance) {
        walletID = id;
        userName = name;
        balance = initial_Balance;
    }

    // Load money into wallet
    void loadMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money loaded successfully!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    // Transfer money to another wallet
    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid transfer amount!\n";
        }
        else if (amount > balance) {
            cout << "Error: Insufficient balance!\n";
        }
        else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful!\n";
        }
    }

    // Display wallet details
    void display() {
        cout << "\nWallet ID: " << walletID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Create two wallets
    Wallet w1("W101", "Krishna", 1000);
    Wallet w2("W102", "harshil", 500);

    // Display initial details
    cout << "Initial Wallet Details:\n";
    w1.display();
    w2.display();

    // Load money
    cout << "\nLoading money into Krishna's wallet...\n";
    w1.loadMoney(500);

    // Transfer money
    cout << "\nTransferring 1200 from Krishna to harshil...\n";
    w1.transferMoney(w2, 1200);

    // Display final details
    cout << "\nFinal Wallet Details:\n";
    w1.display();
    w2.display();

    return 0;
}