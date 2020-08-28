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

#define Log(format, ...) \
    _Log("\33[1;34m[%s,%d,%s] " format "\33[0m\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

int main(){
	int a[] = {10, 23, 2, 5, 999};
	assert(0);
	for(int i = 0; i < 5; i++) cout << a[i] << endl;
	sort(a, a+5);
	for(int i = 0; i < 5; i++) cout << a[i] << endl;
    return 0;
}
