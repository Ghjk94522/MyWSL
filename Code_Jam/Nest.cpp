#include<bits/stdc++.h>
using namespace std;

int pri(vector<int>& src, int st, int ne, string& s){
    if(ne < src.size()){
        s += to_string(src[st]);
        if(src[ne] > src[st]){
            for(int i = src[ne]-src[st]; i > 0; i--){
                s += "(";
            }
            return pri(src, ne, ne+1, s);
        }
        else if(src[ne] <= src[st]){
            if(src[ne] == 0){
                for(int i = src[st]; i > 0; i--) s += ")";
                return ne;
            }
            else{
                for(int i = src[st]-src[ne]; i > 0; i--) s += ")";
                return pri(src, ne, ne+1, s);
            }
        }
    }
    else{
        s += to_string(src[st]);
        for(int i = 0; i < src[st]; i++) s += ")";
        return src.size();
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<string> res, ss;
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        ss.push_back(temp);        
    }
    for(int i = 0; i < n; i++){
        vector<int> src;
        for(int j = 0; j < ss[i].length(); j++){
            int temp = ss[i][j] - '0';
            src.push_back(temp);
        }
        string s = "";
        for(int j = 0; j < src[0]; j++) s += "(";
        if(src.size() >= 2){ 
            int flag = pri(src, 0, 1, s);
            while(flag != src.size()){
                for(int j = 0; j < src[flag]; j++) s += "(";
                flag = pri(src, flag, flag+1, s);
            }
        }
        else{
            s += to_string(src[0]);
            for(int j = 0; j < src[0]; j++) s += ")";
        }
        res.push_back(s);
    }
    for(int i = 0; i < n; i++){
        printf("Case #%d: %s\n", i+1, res[i].c_str());
    }
    return 0;
}