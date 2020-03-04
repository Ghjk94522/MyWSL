#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 10;
    int b = 23;
    cout << a << " " << b << "\n";
    a ^= b;
    b ^= a;
    a ^= b;
    cout << a << " " << b << "\n";  
    return 0;
}