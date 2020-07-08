#include<bits/stdc++.h>
using namespace std;

int x[5000002], k;
void qsort(int l, int r){
    int i = l, j = r;
    int mid = x[(l+r) / 2];
    do{
        while(x[j] > mid) j--;
        while(x[i] < mid) i++;
        if(i <= j){
            swap(x[i], x[j]);
            i++;
            j--;
        }
    } while(i <= j);
    if(k <= j) qsort(l, j);
    else if(i <= k) qsort(i, r);
    else{
        cout << x[j+1] << endl;
        return;
    }
}

int main(){
    int n;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    qsort(0, n-1);
    return 0;
}