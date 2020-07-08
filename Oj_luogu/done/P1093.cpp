#include<bits/stdc++.h>
using namespace std;

struct stu{
    int id;
    int ch;
    int ma;
    int en;
};

bool cmp(stu a, stu b){
    int sa = a.ch + a.ma + a.en;
    int sb = b.ch + b.ma + b.en;
    if(sa > sb) return true;
    else if(sa == sb && a.ch > b.ch) return true;
    else if(sa == sb && a.ch == b.ch &&
            a.id < b.id) return true;
    else return false;
}

int main(){
    int n; cin >> n;
    stu *src = new stu[305];
    for(int i = 1; i <= n; i++){
        src[i].id = i;
        cin >> src[i].ch >> src[i].ma >> src[i].en;
    }
    sort(src+1, src+n+1, cmp);
    for(int i = 1; i <= 5; i++){
        cout << src[i].id << " " << src[i].ch + src[i].ma + \
                src[i].en << endl;
    }
    return 0;
}