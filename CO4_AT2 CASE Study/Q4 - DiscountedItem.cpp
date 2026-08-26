#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item
{
protected:
    int item_no;
    string name;
    double price;

public:
    void acceptItem()
    {
        cout << "Enter item number: ";
        cin >> item_no;

        cin.ignore();
        cout << "Enter item name: ";
        getline(cin, name);

        cout << "Enter price: ";
        cin >> price;
    }
};

class DiscountedItem : public Item
{
    double discount_percent;
    double discount_amount;
    double final_price;

public:
    void accept()
    {
        acceptItem();

        cout << "Enter discount percentage: ";
        cin >> discount_percent;

        discount_amount = price * discount_percent / 100;
        final_price = price - discount_amount;
    }

    void display()
    {
        cout << left << setw(12) << item_no
             << setw(20) << name
             << setw(12) << price
             << setw(12) << discount_percent
             << setw(15) << final_price << endl;
    }

    double getFinalPrice()
    {
        return final_price;
    }
};

int main()
{
    int n;
    double total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    DiscountedItem items[50];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Item " << i + 1 << endl;
        items[i].accept();
    }

    cout << "\n================ ITEM-WISE BILL ================\n";

    cout << left << setw(12) << "Item No"
         << setw(20) << "Name"
         << setw(12) << "Price"
         << setw(12) << "Discount"
         << setw(15) << "Final Price" << endl;

    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        items[i].display();
        total += items[i].getFinalPrice();
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "Total Amount: Rs. " << fixed << setprecision(2) << total << endl;

    return 0;
}
