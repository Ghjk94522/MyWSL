#include<bits/stdc++.h>
using namespace std;

/*
 *
 * According to the luogu answering
 * 
 */

int main(){
    int n; cin >> n;
    int *src = new int[n];
    for(int i = 0; i < n; i++) cin >> src[i];
    int res = src[0];
    for(int i = 1; i < n; i++) if(src[i] > src[i-1]) res += (src[i] - src[i-1]);
    cout << res << endl;
    return 0;
}