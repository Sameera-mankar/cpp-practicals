#include <iostream>
using namespace std;

class Shape
{
public:
    // Pure virtual function makes Shape an abstract class.
    virtual void area() = 0;

    // Virtual destructor ensures proper cleanup of derived objects.
    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void area() override
    {
        if (radius <= 0)
        {
            cout << "Invalid radius for circle.\n";
            return;
        }

        cout << "Area of Circle: " << 3.14 * radius * radius << " m^2\n";
    }
};

class Triangle : public Shape
{
private:
    double height, base;

public:
    Triangle(double h, double b)
    {
        height = h;
        base = b;
    }

    void area() override
    {
        if (height <= 0 || base <= 0)
        {
            cout << "Invalid dimensions for triangle.\n";
            return;
        }

        cout << "Area of Triangle: " << 0.5 * base * height << " m^2\n";
    }
};

class Rectangle : public Shape
{
private:
    double height, width;

public:
    Rectangle(double h, double w)
    {
        height = h;
        width = w;
    }

    void area() override
    {
        if (height <= 0 || width <= 0)
        {
            cout << "Invalid dimensions for rectangle.\n";
            return;
        }

        cout << "Area of Rectangle: " << height * width << " m^2\n";
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    Circle c(5);
    Triangle t(6, 4);
    Rectangle r(8, 12);

    // Shape is abstract and cannot be instantiated directly.
    Shape *ptrs[] = {&c, &t, &r};

    ptrs[0]->area();
    ptrs[1]->area();
    ptrs[2]->area();

    return 0;
}

