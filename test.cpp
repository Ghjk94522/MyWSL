#include<bits/stdc++.h>
using namespace std;

class test{
    int a;
    int b;
public:
    test(int x, int y){ a = x; b = y; }
    int operator + (const test& x);
};

int test:: operator +(const test& x){
    return 1;
}