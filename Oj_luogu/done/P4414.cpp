#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    for(int i = 0; i < 3; i++){
        int temp; cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    string s; cin >> s;
    if(s == "ABC") printf("%d %d %d", a[0], a[1], a[2]);
    else if(s == "BAC") printf("%d %d %d", a[1], a[0], a[2]);
    else if(s == "BCA") printf("%d %d %d", a[1], a[2], a[0]);
    else if(s == "ACB") printf("%d %d %d", a[0], a[2], a[1]);
    else if(s == "CBA") printf("%d %d %d", a[2], a[1], a[0]);
    else if(s == "CAB") printf("%d %d %d", a[2], a[0], a[1]);
    return 0;
}