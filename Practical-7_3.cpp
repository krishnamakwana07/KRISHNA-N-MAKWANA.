#include <iostream>
using namespace std;

class Fahrenheit; // forward declaration

// 🔹 Celsius Class
class Celsius {
public:
    float c;

    Celsius(float c = 0) {
        this->c = c;
    }

    // 🔹 Convert Celsius → Fahrenheit
    operator Fahrenheit();

    void display() {
        cout << c << " °C";
    }
};

// 🔹 Fahrenheit Class
class Fahrenheit {
public:
    float f;

    Fahrenheit(float f = 0) {
        this->f = f;
    }

    // 🔹 Convert Fahrenheit → Celsius
    operator Celsius() {
        return Celsius((f - 32) * 5 / 9);
    }

    void display() {
        cout << f << " °F";
    }

    // 🔹 Equality operator
    bool operator == (Fahrenheit other) {
        return f == other.f;
    }
};

// 🔹 Define conversion outside class
Celsius::operator Fahrenheit() {
    return Fahrenheit((c * 9 / 5) + 32);
}

int main() {

    // 🔹 Conversion demo
    Celsius c1(25);
    Fahrenheit f1 = c1;  // automatic conversion

    cout << "Celsius: ";
    c1.display();
    cout << " → ";
    f1.display();
    cout << endl;

    // 🔹 Reverse conversion
    Fahrenheit f2(77);
    Celsius c2 = f2;

    cout << "Fahrenheit: ";
    f2.display();
    cout << " → ";
    c2.display();
    cout << endl;

    // 🔹 Equality check
    if(f1 == f2) {
        cout << "Temperatures are equal!\n";
    } else {
        cout << "Temperatures are NOT equal!\n";
    }

    // ============================
    // 🔹 1. Dynamic Queue (FIFO)
    // ============================
    int size = 5;
    Fahrenheit* queue = new Fahrenheit[size];
    int front = 0, rear = 0;

    // Enqueue
    queue[rear++] = Fahrenheit(32);
    queue[rear++] = Fahrenheit(68);
    queue[rear++] = Fahrenheit(100);

    cout << "\nQueue (FIFO Processing):\n";
    while(front < rear) {
        queue[front].display();
        cout << " → ";
        Celsius temp = queue[front];  // convert
        temp.display();
        cout << endl;
        front++;
    }

    delete[] queue;

    // ============================
    // 🔹 2. Fixed Array Storage
    // ============================
    Celsius arr[3] = {Celsius(0), Celsius(20), Celsius(37)};

    cout << "\nFixed Array Storage:\n";
    for(int i = 0; i < 3; i++) {
        arr[i].display();
        cout << " → ";
        Fahrenheit temp = arr[i];
        temp.display();
        cout << endl;
    }

    return 0;
}