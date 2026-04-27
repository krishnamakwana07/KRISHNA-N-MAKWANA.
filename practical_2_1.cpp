#include <iostream>
#include <limits>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setDimensions() {
        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Width: ";
        cin >> width;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Length: " << length
             << ", Width: " << width
             << ", Area: " << area()
             << ", Perimeter: " << perimeter() << endl;
    }
};

Rectangle r[100];
int n = 0;

void addRectangle() {
    if (n >= 100) {
        cout << "Maximum limit reached!\n";
        return;
    }
    r[n].setDimensions();
    n++;
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Rectangle\n2. Display Rectangles\n3. Exit\nEnter choice: ";
        
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // reset error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addRectangle();
                break;

            case 2:
                if (n == 0) {
                    cout << "No rectangles to display!\n";
                } else {
                    for (int i = 0; i < n; i++) {
                        r[i].display();
                    }
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);
 
    return 0;
}