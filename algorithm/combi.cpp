#include<bits/stdc++.h>
using namespace std;

int src[10010], ans[10010];

void dfs(int len, int r, int k1, int k2){
    if(k1 == r){
        // one condition and return the result
        for(int i = 0; i < r; i++) cout << ans[i] << " ";
        cout << endl;
        return;
    }
    else{
        for(int i = k2; i < len; i++){
            ans[k1] = src[i];
            dfs(len, r, k1+1, i+1);
        }
    }
}

int main(){
    for(int i = 0; i < 5; i++) cin >> src[i];
    dfs(5, 3, 0, 0);
    return 0;
}