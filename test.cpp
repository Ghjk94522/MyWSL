#include<bits/stdc++.h>
#define NDEBUG
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

int time2int(string a){
    int res = 0;
    string temp = "";
    for(int i = 0; a[i]; i++){
        if(a[i] == ':') break;
        temp += a[i];
    }
    res = stoi(temp);
    return res;
}

int edit(int *a){
    a[0] = 100;
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    string s；
    cout << typeof(getline(cin, s)) << endl;
    return 0;
}