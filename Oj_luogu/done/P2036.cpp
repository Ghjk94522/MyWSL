#include<bits/stdc++.h>
using namespace std;

#define M 15

#ifdef __DFS__

/// find all the conditions and if there are n seasoning
//  there will be 2^n conditions and we find them all

int n;
int ans = 0x7f7f7f7f;
int a[M], b[M];

void dfs(int i, int x, int y){
    if(i > n){
        if(x == 1 && y == 0) return;
        ans = min(abs(x-y), ans);
        return;
    }
    dfs(i+1, x*a[i], y+b[i]);
    dfs(i+1, x, y);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}

#endif

#ifdef __BIT__

int n, s[12], b[12], ans = 0x3f3f3f3f;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i] >> b[i];
    for(int i = 1; i < (1 << n); i++){
        int S = 1, B = 0;
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                S *= s[j];
                B += b[j];
            }
        }
        ans = min(ans, abs(S-B));
    }
    cout << ans << endl;
    return 0;
}

#endif