#include<bits/stdc++.h>
using namespace std;

// Pay attention to the res when it less than zero

int main(){
    int m, t, s;
    cin >> m >> t >> s;
    int d = s / t;
    if(s % t != 0) d++;
    int res = m - d;
    if(res < 0) res = 0;
    cout << res;
    return 0;
}