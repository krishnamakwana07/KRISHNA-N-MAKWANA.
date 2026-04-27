/*A growing organization wants to automate its payroll system to efficiently compute employee
salaries. Each employee's record must store the name, basic salary, and bonus amount.
While most employees receive a default bonus, exceptional performers may receive a
customized bonus.
To enable instant computation of the salary, an inline function will calculate total salary =
basic salary + bonus.
Employee details must be initialized through a constructor, using either default or customized
bonus amounts.
As the organization expands, dynamic storage of employee records is required to support
scalability.
The system must display complete employee details along with their total salary.*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;
public:
    // Constructor with default bonus
    Employee(string empName, double empBasicSalary) {
        name = empName;
        basicSalary = empBasicSalary;
        bonus = 1000; // Default bonus  
    }
    // Constructor with customized bonus
    Employee(string empName, double empBasicSalary, double empBonus) {
        name = empName;
        basicSalary = empBasicSalary;
        bonus = empBonus; // Customized bonus   
    }
    // Inline function to calculate total salary
    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }       
    // Function to display employee details
    void displayEmployeeDetails() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl; 
        cout << "Total Salary: " << calculateTotalSalary() << endl;
    }
};

int main() {
    // Dynamic storage of employee records
    Employee* emp1 = new Employee("Alice", 50000); // Using default bonus
    Employee* emp2 = new Employee("Bob", 60000, 2000); // Using customized bonus

    cout << "Employee 1 Details:" << endl;
    emp1->displayEmployeeDetails();
    cout << endl;

    cout << "Employee 2 Details:" << endl;
    emp2->displayEmployeeDetails();
    cout << endl;

    // Clean up dynamic memory
    delete emp1;
    delete emp2;

    return 0;
}


    