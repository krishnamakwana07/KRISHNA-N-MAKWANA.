#include <iostream>
#include <cmath>
using namespace std;

// Custom Exception Class
class NegativeNumberException {
public:
    const char* message() {
        return "Error: Negative number entered! Cannot compute square root.";
    }
};

int main() {
    double num;

    cout << "Enter a number: ";
    cin >> num;

    try {
        // Check immediately after input
        if(num < 0) {
            throw NegativeNumberException();
        }

        // Compute square root
        cout << "Square Root: " << sqrt(num) << endl;
    }

    catch(NegativeNumberException e) {
        cout << e.message() << endl;
    }

    return 0;
}