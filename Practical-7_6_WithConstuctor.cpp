#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {   // virtual destructor
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];
        cout << "Derived Constructor Called\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived Destructor Called\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // now works correctly
    return 0;
}