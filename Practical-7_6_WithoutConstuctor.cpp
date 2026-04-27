#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];  // dynamic allocation
        cout << "Derived Constructor Called\n";
    }

    ~Derived() {
        delete[] data;  // should free memory
        cout << "Derived Destructor Called\n";
    }
};

int main() {
    Base* ptr = new Derived();  // base pointer → derived object
    delete ptr;  // problem here
    return 0;
}