#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter two integers (a b): ";

        // Read first integer
        if(!(cin >> a)) {
            throw "Invalid input for numerator!";
        }

        // Read second integer AND check division immediately
        if(!(cin >> b)) {
            throw "Invalid input for denominator!";
        }

        if(b == 0) {
            throw "Error: Division by zero!";
        }

        // Perform division immediately
        cout << "Result: " << (float)a / b << endl;
    }

    catch(const char* msg) {
        cout << msg << endl;
    }

    return 0;
}