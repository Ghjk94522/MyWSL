#include<bits/stdc++.h>
using namespace std;

typedef struct{
    short a;
    int b;
} t;

bool cmp(t a, t b){
    if(a.a > b.a) return false;
    else return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    t* src = new t[m];
    for(int i = 0; i < m; i++){
        cin >> src[i].a >> src[i].b;
    }
    sort(src, src+m, cmp);
    int res = 0;
    for(int i = 0; i < m; i++){
        if(n > src[i].b){
            n -= src[i].b;
            res += (src[i].a * src[i].b);
        }
        else{
            res += (src[i].a * n);
            break;
        }
    }
    cout << res << endl;
    return 0;
}