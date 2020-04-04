#include<bits/stdc++.h>
//#define TEST
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> tra, rs, cs;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        vector<vector<int>> src;
        for(int j = 0; j < m; j++){
            int temp = 0;
            vector<int> tempv;
            for(int t = 0; t < m; t++){
                cin >> temp;
                tempv.push_back(temp);
            }
            src.push_back(tempv);
        }
        int trace = 0;
        for(int j = 0; j < m; j++) trace += src[j][j];
        tra.push_back(trace);
        int r = 0;
        for(int j = 0; j < m; j++){
            int flag = 0;
            for(int k = 0; k < m; k++){
                int temp = src[j][k];
                for(int t = k+1; t < m; t++){
                    int now = src[j][t];
                    if(now == temp){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    r++;
                    break;
                }
            }
        }
        rs.push_back(r);
        int p = 0;
        for(int j = 0; j < m; j++){
            int flag = 0;
            for(int k = 0; k < m; k++){
                int temp = src[k][j];
                for(int t = k+1; t < m; t++){
                    int now = src[t][j];
                    if(now == temp){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    p++;
                    break;
                }
            }
        }
        cs.push_back(p);
        #ifdef TEST
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                cout << src[j][k] << " ";
            }
            cout << endl;
        }
        #endif
    }
    for(int i = 0; i < n; i++){
        printf("Case #%d: %d %d %d\n", i+1, tra[i], rs[i], cs[i]);
    }
    return 0;
}