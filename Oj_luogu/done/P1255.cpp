#include<bits/stdc++.h>
using namespace std;

/// 我的第一道高精度加法算法题
//  实际上我第一次看题的时候没注意算法标签，还奇怪为啥这题能到普及-
//  但是提交一次之后发现只有30pts才发现输入到5000，输出已经很大很大了

/*

/// My first version _ 30pts

int n;
int ans;

int dfs(int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else{
        ans += dfs(n-1);
        ans += dfs(n-2);
    }
    return 0;
}

int main(){
    cin >> n;
    ans  = 0;
    dfs(n);
    cout << ans << endl;
    return 0;
}

*/

/// according to the answers in luogu.com
int n, len = 1, f[5005][5005];

void hp(int k){
    int i;
    for(i = 1; i < len; i++)
        f[k][i] = f[k-1][i] + f[k-2][i];
    for(i = 1; i < len; i++){
        if(f[k][i] >= 10){
            f[k][i+1] += f[k][i]/10;
            f[k][i] %= 10;
            if(f[k][len+1]) len++;
        }
    }
}

int main(){
    cin >> n;
    int i;
    f[1][1] = 1; f[2][1] = 2;
    for(i = 3; i < n; i++)
        hp(i);
    for(i = len; i >= 1; i--)
        cout << f[n][i];
    return 0;
}