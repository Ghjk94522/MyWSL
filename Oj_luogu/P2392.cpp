#include<bits/stdc++.h>
using namespace std;

/*
 * 
 * The greedy strategy is wrong, for example:
 * input sample:
 * 4 0 0 0
 * 1 1 50 50
 * 
 */

#ifdef __TRY__

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int *x = new int[a];
    int *y = new int[b];
    int *z = new int[c];
    int *w = new int[d];
    for(int i = 0; i < a; i++){
        cin >> x[i];
    }
    for(int i = 0; i < b; i++){
        cin >> y[i];
    }
    for(int i = 0; i < c; i++){
        cin >> z[i];
    }
    for(int i = 0; i < d; i++){
        cin >> w[i];
    }
    int ans = 0;
    sort(x, x+a);
    sort(y, y+b);
    sort(z, z+c);
    sort(w, w+d);
    int s = 0, e = a-1;
    while(s < e){
        if(x[s] > x[e]){
            x[s] -= x[e];
            ans += x[e];
            e--;
        }
        else{
            x[e] -= x[s];
            ans += x[s];
            s++;
        }
    }
    ans += x[s];
    s = 0, e = b-1;
    while(s < e){
        if(y[s] > y[e]){
            y[s] -= y[e];
            ans += y[e];
            e--;
        }
        else{
            y[e] -= y[s];
            ans += y[s];
            s++;
        }
    }
    ans += y[s];
    s = 0, e = c-1;
    while(s < e){
        if(z[s] > z[e]){
            z[s] -= z[e];
            ans += z[e];
            e--;
        }
        else{
            z[e] -= z[s];
            ans += z[s];
            s++;
        }
    }
    ans += z[s];
    s = 0, e = d-1;
    while(s < e){
        if(w[s] > w[e]){
            w[s] -= w[e];
            ans += w[e];
            e--;
        }
        else{
            w[e] -= w[s];
            ans += w[s];
            s++;
        }
    }
    ans += w[s];
    cout << ans << endl;
    return 0;
}

#endif

