#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    double m1, m2, m3;

public:
    // Default constructor (for testing)
    Student() {
        rollNo = 0;
        name = "Default";
        m1 = m2 = m3 = 0;
    }

    // Parameterized constructor (user input values)
    Student(int r, string n, double a, double b, double c) {
        rollNo = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
    }

    // Function to calculate average
    double average() {
        return (m1 + m2 + m3) / 3;
    }

    // Function to display student details
    void display() {
        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", Marks: [" << m1 << ", " << m2 << ", " << m3 << "]"
             << ", Average: " << average() << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    for (int i = 0; i < n; i++) {
        int choice;

        cout << "\nStudent " << i + 1 << ":\n";
        cout << "1. Use Default Values\n2. Enter Values\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            s[i] = Student(); // default constructor
        } 
        else if (choice == 2) {
            int r;
            string n;
            double a, b, c;

            cout << "Enter Roll No: ";
            cin >> r;

            cout << "Enter Name: ";
            cin >> n;

            cout << "Enter marks in 3 subjects: ";
            cin >> a >> b >> c;

            s[i] = Student(r, n, a, b, c); // parameterized constructor
        } 
        else {
            cout << "Invalid choice! Using default values.\n";
            s[i] = Student();
        }
    }

    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    return 0;
}