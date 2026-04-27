#include<iostream>
using namespace std;

class Shape
{
    protected:
    
    float radius;

    public:

    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{
    public:

    float area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Circle c[3];   // static array of Circle

    for(int i = 0; i < 3; i++)
    {
        float r;
        cout << "Enter radius: ";
        cin >> r;

        c[i].setRadius(r);

        cout << "Area of circle " << i+1 << " is: "
        << c[i].area() << endl;
    }

    return 0;
}