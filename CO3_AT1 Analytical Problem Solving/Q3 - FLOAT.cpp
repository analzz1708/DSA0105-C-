#include <iostream>
using namespace std;

class FLOAT
{
    float value;

public:
    FLOAT()
    {
        value = 0;
    }

    FLOAT(float v)
    {
        value = v;
    }

    FLOAT operator+(FLOAT f)
    {
        return FLOAT(value + f.value);
    }

    FLOAT operator-(FLOAT f)
    {
        return FLOAT(value - f.value);
    }

    FLOAT operator*(FLOAT f)
    {
        return FLOAT(value * f.value);
    }

    FLOAT operator/(FLOAT f)
    {
        return FLOAT(value / f.value);
    }

    void display()
    {
        cout << value << endl;
    }
};

int main()
{
    float a, b;

    cout << "Enter first float value: ";
    cin >> a;

    cout << "Enter second float value: ";
    cin >> b;

    FLOAT f1(a);
    FLOAT f2(b);

    FLOAT add = f1 + f2;
    FLOAT sub = f1 - f2;
    FLOAT mul = f1 * f2;

    cout << "\nAddition: ";
    add.display();

    cout << "Subtraction: ";
    sub.display();

    cout << "Multiplication: ";
    mul.display();

    if (b != 0)
    {
        FLOAT div = f1 / f2;

        cout << "Division: ";
        div.display();
    }
    else
    {
        cout << "Division: Cannot divide by zero." << endl;
    }

    return 0;
}
