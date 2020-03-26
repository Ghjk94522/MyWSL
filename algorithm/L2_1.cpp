#include<bits/stdc++.h>
using namespace std;

// AMAZING!!! There is no time limitation in this question

// version_1 : brute
int main(){
    string pw = "wo yi yue du guan yu chao xi de shuo ming";
    vector<string> src;
    long n; cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        src.push_back(temp);
    }
    long res = 0;
    // for(int i = 0; i < n; i++) cout << src[i] << endl;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(src[i] > src[j]) res++;
        }
    }
    cout << pw << endl << res << endl;
    return 0;
}