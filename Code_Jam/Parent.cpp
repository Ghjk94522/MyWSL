#include<bits/stdc++.h>
using namespace std;

struct ti{
    int st;
    int en;
};

int main(){
    int n; cin >> n;
    vector<string> res;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        vector<ti> temp;
        for(int j = 0; j < m; j++){
            ti now;
            cin >> now.st >> now.en;
            temp.push_back(now);
        }
        
        string r = "C";
        short s1[1441] = {0};
        short s2[1441] = {0};
        for(int j = temp[0].st; j <= temp[0].en; j++) s1[j] = 1;
        for(int j = 1; j < m; j++){
            if(temp[j].en == temp[j].st + 1){
                if(s1[temp[j].en] == 0 || s1[temp[j].st] == 0){
                    r += "C";
                    for(int k = temp[j].st; k <= temp[j].en; k++) s1[k] = 1;
                    continue;
                }
                else if(s2[temp[j].en] == 0 || s2[temp[j].st] == 0){
                    r += "J";
                    for(int k = temp[j].st; k <= temp[j].en; k++) s2[k] = 1;
                    continue;
                }
                else{
                    r = "IMPOSSIBLE";
                    break;
                }
            }
            int flag = 1;
            for(int k = temp[j].st+1; k < temp[j].en; k++){
                if(s1[k] == 1){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                r += "C";
                for(int k = temp[j].st; k <= temp[j].en; k++) s1[k] = 1;
                continue;
            }
            flag = 1;
            for(int k = temp[j].st+1; k < temp[j].en; k++){
                if(s2[k] == 1){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                r += "J";
                for(int k = temp[j].st; k <= temp[j].en; k++) s2[k] = 1;
                continue;
            }
            r = "IMPOSSIBLE";
            break;
        }
        res.push_back(r);
    }
    for(int i = 0; i < n; i++){
        printf("Case #%d: %s\n", i+1, res[i].c_str());
    }
    return 0;
}