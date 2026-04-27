#include <iostream>
#include <iomanip>
using namespace std;

// 🔹 User-defined manipulator
ostream& currency(ostream& output) {
    output << "₹ ";   // You can change to "$ " if needed
    return output;
}

int main() {
    const int n = 3;

    string names[n] = {"Amit", "Neha", "Rahul"};
    int marks[n] = {89, 92, 76};
    float fees[n] = {15000.5, 17500.75, 16000.0};

    // 🔹 Table Header
    cout << setfill('=') << setw(50) << "" << endl;
    cout << setfill(' ');

    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;

    cout << setfill('-') << setw(50) << "" << endl;
    cout << setfill(' ');

    // 🔹 Display Data
    for(int i = 0; i < n; i++) {
        cout << left << setw(15) << names[i]
             << setw(10) << marks[i]
             << currency << fixed << setprecision(2) << fees[i]
             << endl;
    }

    cout << setfill('=') << setw(50) << "" << endl;

    return 0;
}