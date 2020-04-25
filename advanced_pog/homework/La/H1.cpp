#include <bits/stdc++.h>
#define __DEBUG__
using namespace std;

class StrOperation
{
    string str;

public:
    StrOperation(string s)
    {
        str = s;
    }
    bool judgePalindrome();
    void insertStr(int i, string s);
    void replaceStr(int be, int end, string s);
#ifdef __DEBUG__
    void print()
    {
        cout << str << endl;
    }
#endif
};

bool StrOperation ::judgePalindrome()
{
    int i = 0;
    int j = str.length() - 1;
    while (i != j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

void StrOperation ::insertStr(int i, string s)
{
    string temp1 = str.substr(0, i);
    string temp2 = str.substr(i);
    str = temp1 + s + temp2;
}

void StrOperation ::replaceStr(int be, int end, string s)
{
    string temp1 = str.substr(0, be);
    string temp2 = str.substr(end + 1);
    str = temp1 + s + temp2;
}

#ifdef __DEBUG__

int main()
{
    StrOperation test("yzbzy");
    cout << test.judgePalindrome() << endl;
    test.insertStr(3, " oh my yzb ");
    test.print();
    test.replaceStr(10, 12, "");
    test.print();
    return 0;
}

#endif