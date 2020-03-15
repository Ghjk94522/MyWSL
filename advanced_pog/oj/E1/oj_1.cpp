#include<bits/stdc++.h>
#define FOR_TEST
using namespace std;

int judgeStringType(char *s1,char *s2){
    string ss = s1;
    string sd = s2;
    if(ss.length() != sd.length()) return 1;
    if(ss == sd) return 2;
    string temp1 = ss, temp2 = sd;
    transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
    transform(temp2.begin(), temp2.end(), temp2.begin(), ::toupper);
    if(temp1 == temp2) return 3;
    if(ss[0] < sd[0]){
        string temp = ss;
        ss = sd;
        sd = temp;
    }
    int step = ss[0] - sd[0];
    for(int i = 1; ss[i]; i++){
        if(ss[i] >= 'a' && ss[i] <= 'z'){
            char temp = ss[i] + step;
            if(temp > 'z'){
                temp = (temp - 'z' - 1) + 'a';
                if(temp != sd[i]) return 5;
            }
            else if(temp != sd[i]) return 5;
        }
        else{
            char temp = ss[i] + step;
            if(temp > 'Z'){
                temp = (temp - 'Z' - 1) + 'A';
                if(temp != sd[i]) return 5;
            }
            else if(temp != sd[i]) return 5;
        }
    }
    return 4;
}

#ifdef FOR_TEST

int main(){
    char t1[] = "Beijing", t2[] = "cfjkjoh";
    cout << judgeStringType(t1, t2) << endl;
    return 0;
}

#endif