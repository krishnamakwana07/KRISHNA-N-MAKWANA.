#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;

    // Limit for overflow validation
    const int LIMIT = 1000000;

public:
    // Constructor
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    // Display function
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Move function with chaining
    Point& move(int dx, int dy) {
        // Overflow check
        if (abs(x + dx) > LIMIT || abs(y + dy) > LIMIT) {
            cout << "Overflow detected! Move ignored.\n";
            return *this;
        }

        x += dx;
        y += dy;
        return *this; // important for chaining
    }

    // Distance from origin
    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    // Move to absolute coordinates
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // Reset function using pointer
    friend void resetPoint(Point* p);

    // Modify using pointer (pass-by-reference)
    friend void updatePoint(Point* p, int dx, int dy);
};

// ---------------- POINTER FUNCTIONS ----------------
void updatePoint(Point* p, int dx, int dy) {
    p->move(dx, dy);  // direct modification
}

void resetPoint(Point* p) {
    p->setPosition(0, 0);
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    Point p(1, 2);

    cout << "Initial Point: ";
    p.display();

    // Chained moves
    p.move(2, 3).move(-1, 4).move(5, -2);

    cout << "After chained moves: ";
    p.display();

    // Update using pointer
    updatePoint(&p, 3, 3);

    cout << "After pointer update: ";
    p.display();

    // Distance from origin
    cout << "Distance from origin: " << p.distanceFromOrigin() << endl;

    // Reset using pointer
    resetPoint(&p);

    cout << "After reset: ";
    p.display();

    return 0;
}