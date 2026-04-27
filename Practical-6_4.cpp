#include <iostream>
using namespace std;

class Account 
{
    protected:
    int accNumber;
    double balance;

    string history[100];
    int transactionCount;

    public:
    Account(int acc, double bal) 
    {
        accNumber = acc;
        balance = bal;
        transactionCount = 0;
    }

    ~Account() 
    {
        cout<<"Account "<<accNumber<<" deleted.\n";
    }

    void deposit(double amount) 
    {
        balance += amount;
        history[transactionCount++] = "Deposited : " + to_string(amount);
    }

    void withdraw(double amount) 
    {
        if (amount <= balance) 
        {
            balance = balance - amount;
            history[transactionCount++] = "Withdrawn : " + to_string(amount);
        } 
        
        else 
        {
            cout<<"Insufficient balance!\n";
        }
    }

    void display() 
    {
        cout<<"Account Number : "<<accNumber<<endl;
        cout<<"Balance : "<<balance<<endl;
    }

    void showHistory() 
    {
        cout<<"Transaction History:\n";
        for(int i=0; i<transactionCount; i++) 
        {
            cout<<history[i]<<endl;
        }
    }

    void undoLastTransaction() 
    {
        if(transactionCount==0) 
        {
            cout<<"No transaction to undo!\n";
            return;
        }

        string last = history[transactionCount - 1];

        if(last.find("Deposited") != string::npos) 
        {
            double amount = stod(last.substr(11));
            balance = balance - amount;
        } 
        
        else if (last.find("Withdrawn") != string::npos) 
        {
            double amount = stod(last.substr(11));
            balance = balance + amount;
        }

        transactionCount--;
        cout<<"Last transaction undone.\n";
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int acc, double bal, double rate) : Account(acc, bal)
    {
        interestRate = rate;
    }

    void display() 
    {
        Account::display();
        cout<<"Interest Rate : "<<interestRate<<"%"<<endl;
        cout<<"------------------------\n";
    }
};

class CurrentAccount : public Account 
{
    private:
    double overdraftLimit;

    public:
    CurrentAccount(int acc, double bal, double limit) : Account(acc, bal) 
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) 
    {
        if(amount <= balance + overdraftLimit) 
        {
            balance = balance - amount;
            history[transactionCount++] = "Withdrawn: " + to_string(amount);
        } 
        
        else 
        {
            cout<<"Overdraft limit exceeded!\n";
        }
    }

    void display()
    {
        Account::display();
        cout<<"Overdraft Limit : "<<overdraftLimit<<endl;
        cout<<"------------------------\n";
    }
};

int main() 
{
    SavingsAccount s1(101, 5000, 4.5);
    CurrentAccount c1(201, 3000, 2000);

    s1.deposit(1000);
    s1.withdraw(2000);
    s1.display();
    s1.showHistory();

    cout<<endl;

    c1.deposit(500);
    c1.withdraw(4000);
    c1.display();
    c1.showHistory();

    cout<<"\nUndo last transaction (Savings):\n";
    s1.undoLastTransaction();
    s1.display();

    return 0;
}