#include<bits/stdc++.h>
using namespace std;

struct node{
    string s;
    vector<int> v;
};

int main(){
    string pw = "wo yi yue du guan yu chao xi de shuo ming";
    int n; cin >> n;
    vector<node> src;
    for(int i = 0; i < n; i++){
        node temp;
        cin >> temp.s;
        for(int i = 0; i < 26; i++) temp.v.push_back(0);
        for(int i = 0; temp.s[i]; i++) temp.v[temp.s[i]-'a']++;
        src.push_back(temp);
    }
    
    return 0;
}