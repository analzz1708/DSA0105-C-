#include <iostream>
using namespace std;

class Marks
{
protected:
    float mark1, mark2, mark3;

public:
    void accept()
    {
        cout << "Enter marks of Subject 1: ";
        cin >> mark1;

        cout << "Enter marks of Subject 2: ";
        cin >> mark2;

        cout << "Enter marks of Subject 3: ";
        cin >> mark3;
    }
};

class Total : public Marks
{
protected:
    float total;

public:
    void calculateTotal()
    {
        total = mark1 + mark2 + mark3;
    }
};

class Percentage : public Total
{
    float percentage;

public:
    void calculatePercentage()
    {
        percentage = total / 3.0;
    }

    void display()
    {
        cout << "\nTotal Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main()
{
    Percentage student;

    student.accept();
    student.calculateTotal();
    student.calculatePercentage();
    student.display();

    return 0;
}
