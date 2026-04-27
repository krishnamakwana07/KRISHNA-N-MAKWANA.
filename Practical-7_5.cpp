#include <iostream>
using namespace std;

// 🔹 Abstract Base Class
class GradingSystem {
protected:
    float marks;

public:
    GradingSystem(float m) {
        marks = m;
    }

    // Pure virtual function
    virtual char computeGrade() = 0;

    virtual void display() = 0;
};

// 🔹 Undergraduate Class
class Undergraduate : public GradingSystem {
public:
    Undergraduate(float m) : GradingSystem(m) {}

    char computeGrade() {
        if(marks >= 75) return 'A';
        else if(marks >= 60) return 'B';
        else if(marks >= 50) return 'C';
        else return 'F';
    }

    void display() {
        cout << "Undergraduate | Marks: " << marks
             << " | Grade: " << computeGrade() << endl;
    }
};

// 🔹 Postgraduate Class
class Postgraduate : public GradingSystem {
public:
    Postgraduate(float m) : GradingSystem(m) {}

    char computeGrade() {
        if(marks >= 85) return 'A';
        else if(marks >= 70) return 'B';
        else if(marks >= 60) return 'C';
        else return 'F';
    }

    void display() {
        cout << "Postgraduate  | Marks: " << marks
             << " | Grade: " << computeGrade() << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // 🔹 Dynamic array of base class pointers
    GradingSystem** students = new GradingSystem*[n];

    for(int i = 0; i < n; i++) {
        int type;
        float marks;

        cout << "\nStudent " << i+1 << endl;
        cout << "Enter 1 for Undergraduate, 2 for Postgraduate: ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> marks;

        if(type == 1) {
            students[i] = new Undergraduate(marks);
        } else {
            students[i] = new Postgraduate(marks);
        }
    }

    // 🔹 Display all records
    cout << "\n--- Student Records ---\n";
    for(int i = 0; i < n; i++) {
        students[i]->display();   // polymorphism
    }

    // 🔹 Free memory
    for(int i = 0; i < n; i++) {
        delete students[i];
    }
    delete[] students;

    return 0;
}