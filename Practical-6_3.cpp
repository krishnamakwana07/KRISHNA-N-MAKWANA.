#include<iostream>
using namespace std;

class Fuel
{
    protected:
    string fuelType;

    public:
    Fuel(string f)
    {
        fuelType = f;
    }
};

class Brand
{
    protected:
    string brandName;

    public:
    Brand(string b)
    {
        brandName = b;
    }
};

class Car : public Fuel, public Brand
{
    private:
    int carID;

    public:
    Car(int id, string f, string b) : Fuel(f), Brand(b)
    {
        carID = id;
    }

    void display()
    {
        cout<<"Car ID : "<<carID<<endl;
        cout<<"Brand : "<<brandName<<endl;
        cout<<"Fuel Type : "<<fuelType<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main()
{
    cout<<"Processing cars using Array:\n";

    Car cars[3] = { Car(1, "Petrol", "Toyota"),
                    Car(2, "Diesel", "Ford"),
                    Car(3, "Electric", "Tesla") };

    for(int i = 0; i < 3; i++)
    {
        cars[i].display();
    }

    return 0;
}