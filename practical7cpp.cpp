#include <iostream>
using namespace std;

void add(int a, int b)
{
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

void add(double a, double b)
{
    cout << "Sum of " << a << "+" << b << " : " << a + b << "\n";
}

class ComplexNumber
{
    double real, imag;

public:
    ComplexNumber(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    ComplexNumber operator+(const ComplexNumber &obj)
    {
        return ComplexNumber(real + obj.real, imag + obj.imag);
    }

    void display()
    {
        cout << real;

        if (imag >= 0)
        {
            cout << " + " << imag << "i";
        }
        else
        {
            cout << " - " << -imag << "i";
        }

        cout << "\n";
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    add(4, 6);
    add(2.5, 3.8);

    ComplexNumber a(2, -3.5);
    cout << "\nComplex number a: ";
    a.display();

    ComplexNumber b(4.2, 1.5);
    cout << "Complex number b: ";
    b.display();

    ComplexNumber c = a + b;
    cout << "Complex number c: ";
    c.display();

    return 0;
}

