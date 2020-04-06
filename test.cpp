#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
    vector<int> res;
    for(int i = 0; i < n; i++){
        int s, m;
        cin >> s >> m;
        vector<int> temp;
        for(int i = 0; i < s; i++){
            int t; cin >> t;
            temp.push_back(t);
        }
        sort(temp.begin(), temp.end());
        int r = 0; int count = 0;
        while(m > 0){
            m -= temp[count++];
            if(m >= 0) r++;
        }
        res.push_back(r);
    }
    for(int i = 0; i < n; i++) printf("Case #%d: %d\n", i+1, res[i]);
    return 0;
}
