#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;
    int transactionCount;

    static int totalAccounts; // Static data member

public:
    // Constructor
    BankAccount(int accNo, string accName, double bal) {
        accountNumber = accNo;
        name = accName;
        balance = bal;
        transactionCount = 0;
        totalAccounts++;
    }

    // Static function
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Display account info
    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance;
        cout << "\nTransactions: " << transactionCount << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionCount++;
        }
    }

    // Withdraw with minimum balance check
    bool withdraw(double amount) {
        double minBalance = 500; // Minimum balance rule

        if (amount <= 0 || balance - amount < minBalance) {
            cout << "Invalid withdrawal (minimum balance must be maintained).\n";
            return false;
        }

        balance -= amount;
        transactionCount++;
        return true;
    }

    // Transfer function
    bool transfer(BankAccount &receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            cout << "Transfer successful!\n";
            return true;
        } else {
            cout << "Transfer failed.\n";
            return false;
        }
    }

    // Apply service charge
    void applyServiceCharge(double charge) {
        if (balance >= charge) {
            balance -= charge;
            cout << "Service charge applied.\n";
        } else {
            cout << "Insufficient balance for service charge.\n";
        }
    }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

// -------------------- MAIN FUNCTION --------------------
int main() {
    vector<BankAccount*> accounts; // Dynamic storage

    int n = 4; // At least 4 accounts (as required)

    cout << "Creating " << n << " accounts:\n";

    for (int i = 0; i < n; i++) {
        int accNo;
        string name;
        double balance;

        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        accounts.push_back(new BankAccount(accNo, name, balance));
    }

    // Display total accounts
    cout << "\nTotal Accounts Created: " << BankAccount::getTotalAccounts() << endl;

    // ----------- FUND TRANSFER -----------
    int fromAcc, toAcc;
    double amount;

    cout << "\nEnter sender account number: ";
    cin >> fromAcc;
    cout << "Enter receiver account number: ";
    cin >> toAcc;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    BankAccount *sender = nullptr, *receiver = nullptr;

    for (auto acc : accounts) {
        if (acc->getAccountNumber() == fromAcc)
            sender = acc;
        if (acc->getAccountNumber() == toAcc)
            receiver = acc;
    }

    if (sender && receiver) {
        sender->transfer(*receiver, amount);
    } else {
        cout << "Invalid account number(s).\n";
    }

    // ----------- APPLY SERVICE CHARGE -----------
    cout << "\nApplying service charge of 50 to all accounts...\n";
    for (auto acc : accounts) {
        acc->applyServiceCharge(50);
    }

    // ----------- FINAL SUMMARY -----------
    cout << "\nFinal Account Summary:\n";
    for (auto acc : accounts) {
        acc->display();
    }

    // Free memory
    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}