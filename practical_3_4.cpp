#include <iostream>
using namespace std;

// ---------------- DISPLAY ARRAY ----------------
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------- FIND MAX ----------------
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// ---------------- FIND MIN ----------------
template <typename T>
T findMin(T arr[], int n) {
    T minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

// ---------------- REVERSE ARRAY ----------------
template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// ---------------- SEARCH ELEMENT ----------------
template <typename T>
int searchElement(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ---------------- COUNT OCCURRENCES ----------------
template <typename T>
int countOccurrences(T arr[], int n, T key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            count++;
    }
    return count;
}

// ---------------- LEADER ELEMENTS ----------------
template <typename T>
void leaderElements(T arr[], int n) {
    cout << "Leader elements: ";
    
    T maxFromRight = arr[n - 1];
    cout << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            cout << arr[i] << " ";
            maxFromRight = arr[i];
        }
    }
    cout << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {

    // -------- INTEGER ARRAY --------
    int intArr[] = {16, 17, 4, 3, 5, 2};
    int n1 = 6;

    cout << "\n--- INTEGER ARRAY ---\n";
    display(intArr, n1);
    cout << "Max: " << findMax(intArr, n1) << endl;
    cout << "Min: " << findMin(intArr, n1) << endl;

    reverseArray(intArr, n1);
    cout << "Reversed: ";
    display(intArr, n1);

    leaderElements(intArr, n1);

    cout << "Search 5 index: " << searchElement(intArr, n1, 5) << endl;
    cout << "Count of 2: " << countOccurrences(intArr, n1, 2) << endl;


    // -------- FLOAT ARRAY --------
    float floatArr[] = {1.5, 3.2, 0.5, 4.8, 2.1};
    int n2 = 5;

    cout << "\n--- FLOAT ARRAY ---\n";
    display(floatArr, n2);
    cout << "Max: " << findMax(floatArr, n2) << endl;

    reverseArray(floatArr, n2);
    cout << "Reversed: ";
    display(floatArr, n2);

    leaderElements(floatArr, n2);


    // -------- CHARACTER ARRAY --------
    char charArr[] = {'a', 'z', 'b', 'y', 'c'};
    int n3 = 5;

    cout << "\n--- CHARACTER ARRAY ---\n";
    display(charArr, n3);
    cout << "Max (ASCII based): " << findMax(charArr, n3) << endl;

    reverseArray(charArr, n3);
    cout << "Reversed: ";
    display(charArr, n3);

    leaderElements(charArr, n3);

    return 0;
}