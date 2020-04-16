#include<bits/stdc++.h>
using namespace std;

template <typename T>
void f(T) { cout << "f(T)" << endl; }

template <typename T>
void f(const T*) { cout << "f(const T*)" << endl; }

template <typename T>
void g(T) { cout << "g(T)" << endl; }

template <typename T>
void g(T*) { cout << "g(T*)" << endl; }

int main(){
    int a = 1;
    int *b = &a;
    const int c = 0;
    const int *d = &c;
    f(a);
    f(b);
    f(c);
    f(d);
    g(a);
    g(b);
    g(c);
    g(d);
    return 0;
}