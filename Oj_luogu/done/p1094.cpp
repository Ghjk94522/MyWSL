#include<bits/stdc++.h>
using namespace std;
int main(){
    int w; cin >> w;
    int n; cin >> n;
    vector<int> src;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        src.push_back(temp);
    }
    sort(src.begin(), src.end());
    int i = 0, j = n-1;
    int ans = 0;
    while(i <= j){
        if(i == j){
            ans++;
            break;
        }
        if(src[i] + src[j] > w){
            ans++;
            j--;
        }
        else{
            ans++;
            j--;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}