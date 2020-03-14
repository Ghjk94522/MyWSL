#include<iostream>
using namespace std;

class A{
public:
    int x;
    int len;
    int *p;
    A(){
        p = new int(0);
        x = 0;
        len = 0;
    }
    A(int m, int n){
        p = new int(n);
        x = m;
        len = n;
    }
    ~A(){
        delete p;
        x = 0;
        len = 0;
    }
    A& operator = (const A& a){
        if(&a == this) return *this;
        delete[] p;
        x = a.x;
        p = new int[a.len];
        len = a.len;
        for(int i = 0; i < len; i++){
            p[i] = a.p[i];
        }
    }
};
