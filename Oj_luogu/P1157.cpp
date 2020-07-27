#include<bits/stdc++.h>
using namespace std;

int n, r;
int ans[25];
int src[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

void dfs(int m, int start){
    if(m > r){
        for(int i = 0; i < r; i++)
            printf("  %d", ans[i]);
        printf("\n");
        return;
    }
    for(int i = start; i < n; i++){
        // something wrong here because the i will be effected by the last one
        ans[m] = src[i];
        dfs(m+1, start+1);
    }
}

int main(){
    cin >> n >> r;
    ans[25] = { 0 };
    dfs(0, 0);
    return 0;
}