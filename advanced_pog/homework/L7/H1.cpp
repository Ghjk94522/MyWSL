#include<bits/stdc++.h>
using namespace std;

class Base{
public:
    int bar(char x){ return (int) x; }
    virtual int bar(int x){ return 2 * x; }
};

class Derived : public Base{
public:
    int bar(char x){ return (int)(-x); }
    int bar(int x){ return x/2; }
};

int main(){
    Derived obj;
    Base *pObj = &obj;
    cout << pObj->bar((char)(100)) << endl;
    cout << pObj->bar(100) << endl;
    return 0;
}