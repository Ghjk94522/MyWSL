#include<bits/stdc++.h>
using namespace std;

struct can{
    int id;
    string sc;
};

bool cmp(can a, can b){
    if(a.sc.length() > b.sc.length()) return true;
    else if (a.sc.length() < b.sc.length()) return false;
    else{
        for(int i = 0; i < a.sc.length(); i++){
            if(a.sc[i] > b.sc[i]) return true;
            else if(a.sc[i] < b.sc[i]) return false;
        }
    }
}

int main(){
    int n; cin >> n;
    can *src = new can[25];
    for(int i = 1; i <= n; i++){
        src[i].id = i;
        cin >> src[i].sc;
    }
    sort(src+1, src+n+1, cmp);
    cout << src[1].id << endl << src[1].sc << endl;
    return 0;
}