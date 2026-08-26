#include <iostream>
#include <string>
using namespace std;

class books
{
    string author;
    string title;
    double price;
    string publisher;
    int stock;

    static int successfulTransactions;
    static int unsuccessfulTransactions;

    void updatePrice(double newPrice)
    {
        price = newPrice;
    }

public:
    books(string a, string t, double p, string pub, int s)
    {
        author = a;
        title = t;
        price = p;
        publisher = pub;
        stock = s;
    }

    bool searchBook(string searchTitle, string searchAuthor)
    {
        return (title == searchTitle && author == searchAuthor);
    }

    void display()
    {
        cout << "\nAuthor: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }

    void purchase(int copies)
    {
        if (copies <= stock)
        {
            double totalCost = copies * price;
            cout << "Total Cost: Rs. " << totalCost << endl;

            stock -= copies;
            successfulTransactions++;

            cout << "Transaction successful." << endl;
            cout << "Remaining stock: " << stock << endl;
        }
        else
        {
            cout << "Required copies not in stock" << endl;
            unsuccessfulTransactions++;
        }
    }

    void changePrice(double newPrice)
    {
        updatePrice(newPrice);
        cout << "Price updated successfully." << endl;
    }

    static void showStatistics()
    {
        cout << "\nSuccessful Transactions: "
             << successfulTransactions << endl;

        cout << "Unsuccessful Transactions: "
             << unsuccessfulTransactions << endl;
    }
};

int books::successfulTransactions = 0;
int books::unsuccessfulTransactions = 0;

int main()
{
    books book1(
        "R.K. Sharma",
        "C++ Programming",
        450.0,
        "Tech Publications",
        10
    );

    books book2(
        "James Gosling",
        "Java Programming",
        550.0,
        "Computer Press",
        5
    );

    string title, author;
    int copies;

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter author name: ";
    getline(cin, author);

    if (book1.searchBook(title, author))
    {
        book1.display();

        cout << "\nEnter number of copies required: ";
        cin >> copies;

        book1.purchase(copies);
    }
    else if (book2.searchBook(title, author))
    {
        book2.display();

        cout << "\nEnter number of copies required: ";
        cin >> copies;

        book2.purchase(copies);
    }
    else
    {
        cout << "Book is not available." << endl;
    }

    books::showStatistics();

    return 0;
}
