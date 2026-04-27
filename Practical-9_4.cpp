#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    set<int> s;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    // Display using range-based loop (cleaner)
    cout << "\nUnique elements (sorted using set): ";
    for(int val : s) {
        cout << val << " ";
    }
    cout << endl;

    // Convert set → vector
    vector<int> v(s.begin(), s.end());

    cout << "Elements after converting to vector: ";
    for(int val : v) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}