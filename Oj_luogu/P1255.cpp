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
