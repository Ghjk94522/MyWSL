#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k; 
    cin >> n >> k;
    vector<string> src;
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        src.push_back(temp);
    }
    sort(src.begin(), src.end());
    if(n%2 == 0){
        int ind = (n/2 - k - 1);
        for(int i = 0; i <= 2*k; i++)
            cout << src[ind++] << " ";
    }
    else{
        int ind = (n/2 - k);
        for(int i = 0; i <= 2*k; i++)
            cout << src[ind++] << ' ';
    }
    return 0;
}