#include <iostream>
#include <string>
using namespace std;

class Worker
{
protected:
    int code;
    string name;
    float salary;

public:
    void acceptWorker()
    {
        cout << "Enter worker code: ";
        cin >> code;

        cin.ignore();
        cout << "Enter worker name: ";
        getline(cin, name);

        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayWorker()
    {
        cout << "Worker Code: " << code << endl;
        cout << "Worker Name: " << name << endl;
        cout << "Salary: Rs. " << salary << endl;
    }
};

class Officer
{
protected:
    float DA;
    float HRA;

public:
    void acceptOfficer()
    {
        cout << "Enter DA: ";
        cin >> DA;

        cout << "Enter HRA: ";
        cin >> HRA;
    }

    void displayOfficer()
    {
        cout << "DA: Rs. " << DA << endl;
        cout << "HRA: Rs. " << HRA << endl;
    }
};

class Manager : public Worker, public Officer
{
    float TA;
    float gross_sal;

public:
    void calculate()
    {
        TA = salary * 0.10;
        gross_sal = salary + DA + HRA + TA;
    }

    void display()
    {
        cout << "\n===== MANAGER DETAILS =====" << endl;

        displayWorker();
        displayOfficer();

        cout << "TA: Rs. " << TA << endl;
        cout << "Gross Salary: Rs. " << gross_sal << endl;
    }

    void accept()
    {
        acceptWorker();
        acceptOfficer();
        calculate();
    }
};

int main()
{
    Manager m;

    m.accept();
    m.display();

    return 0;
}
