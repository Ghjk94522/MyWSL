#include<bits/stdc++.h>
using namespace std;

// Something wrong with the code but I don't know why

int main(){
    int n; cin >> n;
    unsigned long long res = n / 24 * (n-1) * (n-2) * (n-3);
    printf("%lld", res);
    return 0;
}