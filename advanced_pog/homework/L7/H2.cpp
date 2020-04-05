#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
public:
    A(): a(5){}
    virtual void print() const{
        cout << a << endl;
    }
};

class B: public A{
    char b;
public:
    B(){
        b = 'E';
    }
    void print() const{
        cout << b << endl;
    }
};

void show(A &x){
    x.print();
}

int main(){
    A d1, *p;
    B d2;
    p = &d2;
    d1.print();
    d2.print();
    p->print();
    show(d1);
    show(d2);
    return 0;
}