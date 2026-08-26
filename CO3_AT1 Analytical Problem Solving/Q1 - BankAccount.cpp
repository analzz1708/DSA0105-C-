#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    string name;
    long accountNumber;
    string type;
    double balance;

public:
    BankAccount()
    {
        name = "";
        accountNumber = 0;
        type = "";
        balance = 0.0;
    }

    BankAccount(string n, long acc, string t, double b)
    {
        name = n;
        accountNumber = acc;
        type = t;
        balance = b;
    }

    void deposit(long acc, string customerName, double amount)
    {
        if (acc == accountNumber && customerName == name)
        {
            balance += amount;
            cout << "Amount deposited successfully." << endl;
        }
        else
        {
            cout << "Account number or name is incorrect." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << type << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    ~BankAccount()
    {
        cout << "Bank account object destroyed." << endl;
    }
};

int main()
{
    string name;
    long accountNumber;
    string type;
    double balance;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account type: ";
    cin >> type;

    cout << "Enter initial balance: ";
    cin >> balance;

    BankAccount account(name, accountNumber, type, balance);

    account.display();

    long acc;
    string customerName;
    double amount;

    cout << "\nEnter account number for deposit: ";
    cin >> acc;

    cin.ignore();
    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter deposit amount: ";
    cin >> amount;

    account.deposit(acc, customerName, amount);

    cout << "\nEnter withdrawal amount: ";
    cin >> amount;

    account.withdraw(amount);

    account.display();

    return 0;
}
