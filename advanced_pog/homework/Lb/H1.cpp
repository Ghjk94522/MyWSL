#include<bits/stdc++.h>
using namespace std;

int main(){
    printf("x\tsin(x)    cos(x)    tan(x)\n");
    for(int i = 1; i < 11; i++){
        printf("%-2d\t%-10.5lf%-10.5lf%-10.5lf\n", i, sin(i/57.3), cos(i/57.3), tan(i/57.3));
    }
    return 0;
}