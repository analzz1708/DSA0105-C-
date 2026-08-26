#include <iostream>
#include <string>
using namespace std;

class String
{
    string str;

public:
    String()
    {
        str = "";
    }

    String(string s)
    {
        str = s;
    }

    bool operator==(String s)
    {
        return str == s.str;
    }

    bool operator>(String s)
    {
        return str > s.str;
    }

    bool operator<(String s)
    {
        return str < s.str;
    }

    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    getline(cin, s1);

    cout << "Enter second string: ";
    getline(cin, s2);

    String str1(s1);
    String str2(s2);

    if (str1 == str2)
        cout << "Both strings are equal." << endl;
    else if (str1 > str2)
        cout << "First string is greater than second string." << endl;
    else if (str1 < str2)
        cout << "First string is smaller than second string." << endl;

    return 0;
}
