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

int main(){
    vector<test *> tes;
    test *a = new test(1, 2);
    test *b = new test(3, 4);
    tes.push_back(a);
    tes.push_back(b);
    cout << tes.size() << endl;
    
    return 0;
}