#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// -------------------- RECURSIVE SUM --------------------
int recursiveSum(vector<int>& arr, int n) {
    // Base case
    if (n == 0)
        return 0;

    // Recursive case
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

// -------------------- ITERATIVE SUM --------------------
int iterativeSum(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

// -------------------- RECURSIVE MAX --------------------
int recursiveMax(vector<int>& arr, int n) {
    if (n == 1)
        return arr[0];

    int maxPrev = recursiveMax(arr, n - 1);
    return (arr[n - 1] > maxPrev) ? arr[n - 1] : maxPrev;
}

// -------------------- ITERATIVE MAX --------------------
int iterativeMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// -------------------- PREFIX SUM (RECURSIVE) --------------------
void recursivePrefixSum(vector<int>& arr, vector<int>& prefix, int n) {
    if (n == 0)
        return;

    recursivePrefixSum(arr, prefix, n - 1);

    if (n == 1)
        prefix[n - 1] = arr[n - 1];
    else
        prefix[n - 1] = prefix[n - 2] + arr[n - 1];
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ----------- SUM COMPARISON -----------
    auto start1 = chrono::high_resolution_clock::now();
    int recSum = recursiveSum(arr, n);
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    int itrSum = iterativeSum(arr);
    auto end2 = chrono::high_resolution_clock::now();

    chrono::duration<double> recTime = end1 - start1;
    chrono::duration<double> itrTime = end2 - start2;

    cout << "\nSum using recursion: " << recSum;
    cout << "\nSum using iteration: " << itrSum;

    cout << "\nRecursive Time: " << recTime.count() << " seconds";
    cout << "\nIterative Time: " << itrTime.count() << " seconds\n";

    // ----------- MAX ELEMENT -----------
    cout << "\nMaximum (Recursive): " << recursiveMax(arr, n);
    cout << "\nMaximum (Iterative): " << iterativeMax(arr) << endl;

    // ----------- PREFIX SUM -----------
    vector<int> prefix(n);
    recursivePrefixSum(arr, prefix, n);

    cout << "\nPrefix Sum Array:\n";
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }

    cout << endl;

    return 0;
}