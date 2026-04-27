#include <iostream>
#include <vector>
#include <algorithm>  // for reverse()
using namespace std;

// Function to display vector
void display(const vector<int>& v) {
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << "\nOriginal Vector: ";
    display(v);

    // ============================
    // Method 1: Using std::reverse()
    // ============================
    vector<int> v1 = v; // copy
    reverse(v1.begin(), v1.end());

    cout << "Reversed (std::reverse): ";
    display(v1);

    // ============================
    // Method 2: Manual using iterators
    // ============================
    vector<int> v2 = v; // copy

    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while(start < end) {
        // swap values
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

    cout << "Reversed (manual iterators): ";
    display(v2);

    return 0;
}