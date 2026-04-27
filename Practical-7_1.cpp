#include <iostream>
using namespace std;

class Calculator {
private:
    double results[20];   // store results
    int index;

public:
    Calculator() {
        index = 0;
    }

    // 🔹 Overloaded add functions

    int add(int a, int b) {
        int res = a + b;
        results[index++] = res;
        return res;
    }

    float add(float a, float b) {
        float res = a + b;
        results[index++] = res;
        return res;
    }

    double add(int a, double b) {
        double res = a + b;
        results[index++] = res;
        return res;
    }

    double add(double a, int b) {
        double res = a + b;
        results[index++] = res;
        return res;
    }

    double add(double a, double b) {
        double res = a + b;
        results[index++] = res;
        return res;
    }

    // 🔹 Display all stored results
    void displayResults() {
        cout << "\nStored Results:\n";
        for(int i = 0; i < index; i++) {
            cout << "Result " << i+1 << " : " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    // 🔹 Different test cases
    cout << "int + int: " << calc.add(10, 20) << endl;
    cout << "float + float: " << calc.add(2.5f, 3.5f) << endl;
    cout << "int + double: " << calc.add(5, 6.7) << endl;
    cout << "double + int: " << calc.add(8.2, 3) << endl;
    cout << "double + double: " << calc.add(4.5, 2.3) << endl;

    // 🔹 Display all results
    calc.displayResults();

    return 0;
}