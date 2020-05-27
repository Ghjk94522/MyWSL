#include<bits/stdc++.h>
using namespace std;

/*
 *
 * The first version that written by myself
 * but it's a pity that it's wrong 
 * 

int main(){
    int n, x;
    cin >> n >> x; // n means num of boxs, and x means maximum
    vector<int> src;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        src.push_back(temp);
    }
    int res = 0;
    for(int i = 1; i < n; i++){
        if(src[i] + src[i-1] > x){
            if(src[i] >= (src[i] + src[i-1]) - x){
                int t = (src[i] + src[i-1] - x);
                src[i] -= t;
                res += t;
            }
            else{
                int t = (src[i] + src[i-1] - x);
                //src[i] = 0;
                src[i-1] -= (src[i-1] - x);
                src[i] = 0;
                res += t;
            }
        }
    }
    cout << res << endl;
    return 0;
}

 *
 * 
 */

// The second version according to luogu answering
// It's surprising that my idea is totally right. And maybe no answer just because too much input
// use iterating try again

int main(){
    long long n , x , ans , p , t;
    ios::sync_with_stdio(0);//关闭同步流加快速度，c++党必学。
    cin >> n >> x >> p;//输入，注意多输入一个p。
    for ( int i = 1 ; i < n ; i++ )//判断 n-1 个盒子，用 for 循环。
    {
        cin >> t;//输入当前盒子的糖果数，
        if ( t + p > x )//如果不满足要求（两盒糖果总和比x多）
        ans += t + p - x , t = x - p;//就让小A吃掉相应的糖果数，刚好等于x，ans也加上。
        p = t;//现在的盒子有变成了前一个盒子，把t赋值给p。
                //友情提示，不要用while循环一个一个减，后面几个点会超时哦～！
    }
    cout << ans;//输出答案。
    return 0;//养成好习惯，返回0
}