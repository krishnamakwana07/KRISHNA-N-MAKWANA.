#include <iostream>
using namespace std;

// ---------------- MERGE FUNCTION ----------------
int* mergeArrays(int* arr1, int n, int* arr2, int m, int &comparisons, int &moves) {
    int* merged = new int[n + m];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        comparisons++;
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
        moves++;
    }

    // Copy remaining elements
    while (i < n) {
        merged[k++] = arr1[i++];
        moves++;
    }

    while (j < m) {
        merged[k++] = arr2[j++];
        moves++;
    }

    return merged;
}

// ---------------- REMOVE DUPLICATES ----------------
int* removeDuplicates(int* arr, int size, int &newSize) {
    int* temp = new int[size];
    newSize = 0;

    for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            temp[newSize++] = arr[i];
        }
    }

    int* result = new int[newSize];
    for (int i = 0; i < newSize; i++)
        result[i] = temp[i];

    delete[] temp;
    return result;
}

// ---------------- DISPLAY FUNCTION ----------------
void display(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    cout << "Enter size of second array: ";
    cin >> m;

    int* arr1 = new int[n];
    int* arr2 = new int[m];

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int comparisons = 0, moves = 0;

    int* merged = mergeArrays(arr1, n, arr2, m, comparisons, moves);

    cout << "\nMerged Sorted Array:\n";
    display(merged, n + m);

    // Remove duplicates (supplementary)
    int newSize;
    int* uniqueArr = removeDuplicates(merged, n + m, newSize);

    cout << "After Removing Duplicates:\n";
    display(uniqueArr, newSize);

    // Stats
    cout << "\nComparisons: " << comparisons << endl;
    cout << "Moves: " << moves << endl;

    // Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;
    delete[] uniqueArr;

    return 0;
}