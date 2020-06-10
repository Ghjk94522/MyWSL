#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    int t = 0x3f3f;
    while(t != 0){
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int gcd_f(int x, int y){
    if(y == 0) return x;
    else return gcd_f(y, x % y);
}

int fac(int n){
    int res = 1;
    while(n > 1){
        res *= n;
        n--;
    }
    return res;
}

int fac_f(int n){
    if(n == 1) return n;
    else return n * fac_f(n-1);
}

int main(){

}