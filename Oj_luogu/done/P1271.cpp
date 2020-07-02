#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;
    int a[1001] = {0};
    for(int i = 0; i < m; i++){
        int ind; cin >> ind;
        a[ind]++;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > 0){
            for(int j = 0; j < a[i]; j++)
                cout << i << ' ';
        }
    }
    return 0;
}