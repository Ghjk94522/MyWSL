#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) {
            return false;
            break;
        }
    }
    return true;
}

int n, k;
long long ans;
int p[25];

void dfs(int m, int sum, int start){
    if(m == k){
        if(is_prime(sum)) ans++;
        return;
    }
    for(int i = start; i < n; i++)
        dfs(m+1, sum+p[i], i+1);
}

int main(){   
    cin >> n >> k;
    ans = 0;
    for(int i = 0; i < n; i++) cin >> p[i];
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}