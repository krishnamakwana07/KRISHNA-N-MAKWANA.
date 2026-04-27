#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // 🔹 Constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // 🔹 Overload + operator
    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // 🔹 Overload - operator
    Complex operator - (const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // 🔹 Display function
    void display() {
        cout << real;
        if(imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex c1(4, 5);
    Complex c2(2, 3);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition Result: ";
    sum.display();

    cout << "Subtraction Result: ";
    diff.display();

    // 🔹 Optional: Array of complex numbers
    Complex arr[3] = { Complex(1,2), Complex(3,4), Complex(5,6) };

    cout << "\nBatch Display:\n";
    for(int i = 0; i < 3; i++) {
        arr[i].display();
    }

    return 0;
}