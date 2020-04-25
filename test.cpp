#include<bits/stdc++.h>
using namespace std;

class test{
    int a;
    int b;
public:
    test(int x, int y){ a = x; b = y; }
    int operator + (const test& x);
    void print(){cout << a << endl;}
};

int test:: operator +(const test& x){
    return a + b + x.a + x.b;
}

string insertStr(string str, int i, string s)
{
    string temp1 = str.substr(0, i);
    string temp2 = str.substr(i);
    str = temp1 + s + temp2;
    return str;
}

int main(){
    string s = "Hello code";
    s = insertStr(s, 5, " Visual Studio");
    cout << s << endl;
    return 0;
}