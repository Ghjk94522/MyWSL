#include<bits/stdc++.h>
using namespace std;

int Find(int *p, int x){
    if(p[x] != x) return Find(p, p[x]);
    else return x;
}

int Union(int x, int y, int *r, int *p){
    if(r[y] >= r[x]){
        p[Find(p, x)] = Find(p, y);
        if(r[y] == r[x]) r[y]++;
    }
    else{
        p[Find(p, y)] = Find(p, x);
    }
    return 0;
}

int main(){
    int n, m;
    int *p = new int[n+1];
    int *r = new int[n+1];
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) r[i] = 1;
    r[0] = 0;
    for(int i = 0; i < m; i++){
        int f, x, y;
        cin >> f >> x >> y;
        if(f == 1){
            Union(x, y, r, p);
        }
        else{
            cout << (Find(p, x) == Find(p, y) ? "Y\n" : "N\n");
        }
    }
    return 0;
}