#include<bits/stdc++.h>
using namespace std;

int time2int(string a){
    int res = 0;
    string temp = "";
    for(int i = 0; a[i]; i++){
        if(a[i] == ':') break;
        temp += a[i];
    }
    res = stoi(temp);
    return res;
}

int main(){
    printf("Input the schedule of A, each duration written in one line and separated by space : \n");
    printf("The number of durations : \n");
    int n; cin >> n;
    vector<string> a;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        a.push_back(temp);
        cin >> temp;
        a.push_back(temp);
    }
    printf("Input the schedule of A, each duration written in one line and separated by space : \n");
    printf("The number of durations : \n");
    cin >> n;
    vector<string> b;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        b.push_back(temp);
        cin >> temp;
        b.push_back(temp);
    }
    ofstream out;
    out.open("./database/A.dat", ios::out | ios::binary);
    for(int i = 0; i < a.size(); i+=2){
        cout << a[i] << "\t" << a[i+1] << endl;
    }
    out.close();
    out.open("./database/B.dat", ios::out | ios::binary);
    for(int i = 0; i < b.size(); i+=2){
        cout << b[i] << "\t" << b[i+1] << endl;
    }
    out.close();
    vector<string> c;
    for(int i = 0; i < a.size(); i+=2){
        int is = time2int(a[i]);
        int ie = time2int(a[i+1]);
        for(int j = 0; j < b.size(); j+=2){
            int js = time2int(b[j]);
            int je = time2int(b[j+1]);
            if(is >= js && is <= je){

            }
            else if(js >= is && js <= ie){
                
            }
        }
    }
}