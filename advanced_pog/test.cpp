#include<bits/stdc++.h>
using namespace std;

int main(){
    int *p = new int [10];
    for(int i = 0; i < 10; i++){
        p[i] = i;
    }
    cout << sizeof(p)/sizeof(int) << endl;
    int a[] = {1,2,3,4,5,6};
    cout << sizeof(a)/sizeof(int) << endl;
    return 0;
}