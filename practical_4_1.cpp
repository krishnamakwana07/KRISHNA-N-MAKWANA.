#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // ---------------- INSERT AT END ----------------
    void insertEnd(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;
    }

    // ---------------- INSERT AT INDEX ----------------
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index!\n";
            return;
        }

        int* newArr = new int[size + 1];

        for (int i = 0, j = 0; i < size + 1; i++) {
            if (i == index)
                newArr[i] = value;
            else
                newArr[i] = arr[j++];
        }

        delete[] arr;
        arr = newArr;
        size++;
    }

    // ---------------- DELETE AT INDEX ----------------
    void deleteAt(int index) {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index)
                newArr[j++] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        size--;
    }

    // ---------------- DISPLAY ----------------
    void display() {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // ---------------- SEARCH ----------------
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    // ---------------- COUNT OCCURRENCES ----------------
    int countOccurrences(int value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                count++;
        }
        return count;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    DynamicArray da;

    cout << "---- INSERTIONS ----\n";
    da.insertEnd(10);
    da.display();

    da.insertEnd(20);
    da.display();

    da.insertEnd(30);
    da.display();

    da.insertEnd(40);
    da.display();

    da.insertEnd(50);
    da.display();

    cout << "\n---- INSERT AT INDEX ----\n";
    da.insertAt(2, 25);
    da.display();

    cout << "\n---- DELETIONS ----\n";
    da.deleteAt(0);
    da.display();

    da.deleteAt(2);
    da.display();

    da.deleteAt(3);
    da.display();

    cout << "\n---- SEARCH ----\n";
    int pos = da.search(30);
    if (pos != -1)
        cout << "Element 30 found at index: " << pos << endl;
    else
        cout << "Element not found\n";

    cout << "\n---- COUNT OCCURRENCES ----\n";
    cout << "Count of 20: " << da.countOccurrences(20) << endl;

    return 0;
}