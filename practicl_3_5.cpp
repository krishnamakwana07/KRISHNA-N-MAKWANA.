#include <iostream>
#include <string>
using namespace std;

// ---------------- RECURSIVE SUPER DIGIT ----------------
int superDigitRecursive(long long num, int &depth) {
    depth++; // track recursion depth

    // Base case
    if (num < 10)
        return num;

    // Sum of digits
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return superDigitRecursive(sum, depth);
}

// ---------------- MAIN LOGIC ----------------
int superDigit(string n, int k, int &depth) {
    long long initialSum = 0;

    // Sum digits of string n
    for (char c : n) {
        initialSum += (c - '0');
    }

    // Multiply by k instead of concatenating string
    initialSum *= k;

    // Call recursive function
    return superDigitRecursive(initialSum, depth);
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        string n;
        int k;

        cout << "\nEnter number (string): ";
        cin >> n;
        cout << "Enter k: ";
        cin >> k;

        int depth = 0;

        int result = superDigit(n, k, depth);

        cout << "Super Digit: " << result << endl;
        cout << "Recursion Depth: " << depth << endl;
    }

    return 0;
}