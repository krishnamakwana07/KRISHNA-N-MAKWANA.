/*A regional bank wants a system to manage loan accounts. Each loan must store:
 Loan ID
 Applicant name
 Total loan amount
 Annual interest rate
 Loan tenure (months)
The system must calculate the Monthly EMI using the formula:

11
The system should initialize data using both default and parameterized constructors and
display complete loan details. Implement the system using C++ classes and demonstrate its functionality in the main function.*/

#include <iostream>
#include <cmath>

using namespace std;
class Loan {
private:
    int loanID;
    string applicantName;
    double totalLoanAmount;
    double annualInterestRate;
    int loanTenure; // in months
public:
    // Default constructor  
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        totalLoanAmount = 0.0;
        annualInterestRate = 0.0;
        loanTenure = 0;
    }
    // Parameterized constructor
    Loan(int id, string name, double amount, double interestRate, int tenure) {
        loanID = id;
        applicantName = name;
        totalLoanAmount = amount;
        annualInterestRate = interestRate;
        loanTenure = tenure;
    }
    // Function to calculate Monthly EMI
    double calculateEMI() {
        double monthlyInterestRate = annualInterestRate / 12 / 100;
        double emi = (totalLoanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, loanTenure)) /
                     (pow(1 + monthlyInterestRate, loanTenure) - 1);
        return emi;
    }
    // Function to display loan details
    void display() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Total Loan Amount: " << totalLoanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << loanTenure << " months" << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};      
int main() {
    // Creating loan objects using default and parameterized constructors
    Loan loan1; // Default constructor
    Loan loan2(101, "Alice", 50000, 10, 24); // Parameterized constructor

    // Displaying loan details
    cout << "Loan Details for Loan 1 (Default Constructor):" << endl;
    loan1.display();
    cout << "\nLoan Details for Loan 2 (Parameterized Constructor):" << endl;
    loan2.display();

    return 0;
}

