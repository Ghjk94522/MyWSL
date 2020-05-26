/*
Recording to luogu.com answering
*/

#include<bits/stdc++.h>
// #define __DEBUG__
using namespace std;

typedef struct {
    int a;
    int b;
} point;

bool cmp(point a, point b){
    if(a.b < b.b) return true;
    else if(a.b > b.b) return false;
    else if(a.a < b.a) return true;
    else return false;
}

int main(){
    int n; cin >> n;
    vector<point> src;
    for(int i = 0; i < n; i++){
        point temp;
        cin >> temp.a >> temp.b;
        src.push_back(temp);
    }
    #ifdef __DEBUG__
    for(int i = 0; i < n; i++) cout << src[i].a << " " << src[i].b << endl;
    #endif
    sort(src.begin(), src.end(), cmp);
    int res = 1;
    int last = 0;
    #ifdef __DEBUG__
    for(int i = 0; i < n; i++) cout << src[i].a << " " << src[i].b << endl;
    #endif
    for(int i = 1; i < n; i++){
        if(src[i].a >= src[last].b){
            res++;
            last = i;
        }
    }
    cout << res << endl;
    return 0;
}