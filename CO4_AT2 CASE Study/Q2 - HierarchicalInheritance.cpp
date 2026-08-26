#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    string address;
    long long phone_no;

public:
    void acceptPerson()
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter address: ";
        getline(cin, address);

        cout << "Enter phone number: ";
        cin >> phone_no;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
};

class Employee : public Person
{
    int eno;
    string ename;

public:
    void accept()
    {
        cout << "\nEnter Employee Number: ";
        cin >> eno;

        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, ename);

        acceptPerson();
    }

    void display()
    {
        cout << "\nEmployee Details" << endl;
        cout << "Employee Number: " << eno << endl;
        cout << "Employee Name: " << ename << endl;
        displayPerson();
    }
};

class Manager : public Person
{
    string designation;
    string department_name;
    double basic_salary;

public:
    void accept()
    {
        cin.ignore();

        cout << "\nEnter Manager Name: ";
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Phone Number: ";
        cin >> phone_no;

        cin.ignore();

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Department Name: ";
        getline(cin, department_name);

        cout << "Enter Basic Salary: ";
        cin >> basic_salary;
    }

    void display()
    {
        cout << "\nManager Details" << endl;
        displayPerson();
        cout << "Designation: " << designation << endl;
        cout << "Department: " << department_name << endl;
        cout << "Basic Salary: Rs. " << basic_salary << endl;
    }

    double getSalary()
    {
        return basic_salary;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    int n;

    cout << "Enter number of employees and managers: ";
    cin >> n;

    Employee employees[50];
    Manager managers[50];

    int choice;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Accept details" << endl;
        cout << "2. Display details" << endl;
        cout << "3. Display manager with highest salary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Employee Details" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nEmployee " << i + 1 << endl;
                employees[i].accept();
            }

            cout << "\nEnter Manager Details" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nManager " << i + 1 << endl;
                managers[i].accept();
            }

            break;

        case 2:
            cout << "\n===== EMPLOYEES =====" << endl;

            for (int i = 0; i < n; i++)
            {
                employees[i].display();
            }

            cout << "\n===== MANAGERS =====" << endl;

            for (int i = 0; i < n; i++)
            {
                managers[i].display();
            }

            break;

        case 3:
        {
            int highest = 0;

            for (int i = 1; i < n; i++)
            {
                if (managers[i].getSalary() > managers[highest].getSalary())
                {
                    highest = i;
                }
            }

            cout << "\nManager with Highest Basic Salary:" << endl;
            managers[highest].display();

            break;
        }

        case 4:
            cout << "Program exited." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}
