#include <iostream>
using namespace std;

// Global log storage (basic array)
string logs[100];
int logIndex = 0;

// Function to add logs
void addLog(string msg) {
    logs[logIndex++] = msg;
}

// BankAccount Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
        addLog("BankAccount created with balance: " + to_string(balance));
    }

    void deposit(double amount) {
        addLog("Entered deposit()");
        if(amount <= 0) {
            throw "Invalid deposit amount!";
        }
        balance += amount;
        addLog("Deposit successful");
        addLog("Exiting deposit()");
    }

    void withdraw(double amount) {
        addLog("Entered withdraw()");
        if(amount > balance) {
            throw "Insufficient balance!";
        }
        if(amount <= 0) {
            throw "Invalid withdrawal amount!";
        }
        balance -= amount;
        addLog("Withdrawal successful");
        addLog("Exiting withdraw()");
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

// Transaction function (demonstrates stack unwinding)
void performTransaction(BankAccount& acc) {
    addLog("Entered performTransaction()");

    acc.deposit(500);
    acc.withdraw(2000);   // This will throw exception

    addLog("Exiting performTransaction()");
}

int main() {
    try {
        addLog("Entered main()");
        
        BankAccount acc(1000);

        performTransaction(acc);

        addLog("Exiting main()");
    }
    catch(const char* msg) {
        addLog("Exception caught in main()");
        cout << "Exception: " << msg << endl;
    }

    // Display logs
    cout << "\n--- Transaction Logs ---\n";
    for(int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}