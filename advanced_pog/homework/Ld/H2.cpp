#include<bits/stdc++.h>
using namespace std;

string tran(string s){
    string res;
    for(int i = 0; s[i]; i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            res += (s[i] + 32);
        else res += s[i];
    }
    return res;
}

string tran_f(string s){
    if(s[0] >= 'a' && s[0] <= 'z') return (s[0]+32) + tran_f(s.substr(1, s.length()));
    else return s[0] + tran_f(s.substr(1, s.length()));
}

int mul(int a[], int n){
    int res = 1;
    for(int i = 0; i < n; i++) res *= a[i];
    return res;
}

int mul_f(int a[], int n){
    if(n == 0) return a[0];
    else return a[n] * mul_f(a, n-1);
}

string urlMaker(string prot, string tail){
    return prot + tail;
}

def urlMaker(prot):
    def next(tail):
        return prot + tail
    return next