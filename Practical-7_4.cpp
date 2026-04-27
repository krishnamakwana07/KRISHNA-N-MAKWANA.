#include <iostream>
using namespace std;

// 🔹 Base Class
class Shape {
public:
    virtual float Area() = 0;   // pure virtual function
};

// 🔹 Rectangle Class
class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float Area() {
        return length * width;
    }
};

// 🔹 Circle Class
class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float Area() {
        return 3.1416 * radius * radius;
    }
};

int main() {

    // ============================
    // 🔹 Polymorphism Demo
    // ============================
    Shape* s;

    Rectangle r1(5, 4);
    Circle c1(3);

    s = &r1;
    cout << "Rectangle Area: " << s->Area() << endl;

    s = &c1;
    cout << "Circle Area: " << s->Area() << endl;

    // ============================
    // 🔹 1. Dynamic Storage
    // ============================
    int n = 3;
    Shape** shapes = new Shape*[n];

    shapes[0] = new Rectangle(2, 3);
    shapes[1] = new Circle(2.5);
    shapes[2] = new Rectangle(4, 6);

    cout << "\nDynamic Storage Areas:\n";
    for(int i = 0; i < n; i++) {
        cout << "Area " << i+1 << " : " << shapes[i]->Area() << endl;
    }

    // Free memory
    for(int i = 0; i < n; i++) {
        delete shapes[i];
    }
    delete[] shapes;

    // ============================
    // 🔹 2. Static Storage
    // ============================
    Rectangle rects[2] = { Rectangle(3, 5), Rectangle(6, 2) };
    Circle circles[2] = { Circle(1), Circle(4) };

    cout << "\nStatic Storage Areas:\n";

    for(int i = 0; i < 2; i++) {
        cout << "Rectangle " << i+1 << " : " << rects[i].Area() << endl;
    }

    for(int i = 0; i < 2; i++) {
        cout << "Circle " << i+1 << " : " << circles[i].Area() << endl;
    }

    return 0;
}