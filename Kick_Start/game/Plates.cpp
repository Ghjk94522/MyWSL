#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int max = 0;
        int n, k; cin >> n >> k;
        vector<vector<int>> src;
        for(int j = 0; j < n; j++){
            vector<int> r;
            for(int m = 0; m < k; m++){
                int temp; cin >> temp;
                r.push_back(temp);
            }
            src.push_back(r);
        }
        for(int j = 0; j < n; j++){
            int tempm = 0;
            for(int m = k-1; m >= 0; m--){
                tempm += src[j][m];
                
            }
        }
    }
}