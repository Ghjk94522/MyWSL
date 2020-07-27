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

#define Log(format, ...) \
    _Log("\33[1;34m[%s,%d,%s] " format "\33[0m\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

int main(){
    char *arg = "0x1010";
    arg += 2;
    printf("%s\n", arg);
    char s[100];
    for(int i = 0; i < 4; i++){
	s[i] = *arg;
	arg++;
    }
    printf("%s\n", s);
    return 0;
}
