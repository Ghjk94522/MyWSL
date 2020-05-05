#include<bits/stdc++.h>
using namespace std;

/// Function : transfer the string to a int
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
    printf("Input the duration : \n");
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
    printf("Input the duration : \n");
    vector<string> b;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        b.push_back(temp);
        cin >> temp;
        b.push_back(temp);
    }
    // record the A.dat and B.dat with binary data
    // only record the int
    ofstream out;
    out.open("./database/A.dat", ios::out | ios::binary);
    for(int i = 0; i < a.size(); i+=2){
        int a1 = time2int(a[i]);
        int a2 = time2int(a[i+1]);
        out.write((char*)&a1, sizeof(a1));
        out.write((char*)&a2, sizeof(a2));
        //out << a[i] << "\t" << a[i+1] << endl;
    }
    out.close();
    out.open("./database/B.dat", ios::out | ios::binary);
    for(int i = 0; i < b.size(); i+=2){
        int b1 = time2int(b[i]);
        int b2 = time2int(b[i+1]);
        out.write((char*)&b1, sizeof(b1));
        out.write((char*)&b2, sizeof(b2));
        //out << b[i] << "\t" << b[i+1] << endl;
    }
    out.close();
    vector<int> c;
    for(int i = 0; i < a.size(); i+=2){
        int is = time2int(a[i]);
        int ie = time2int(a[i+1]);
        for(int j = 0; j < b.size(); j+=2){
            int js = time2int(b[j]);
            int je = time2int(b[j+1]);
            if(is >= js && is <= je){
                if(ie >= je){
                    c.push_back(is);
                    c.push_back(je);
                }
            }
            else if(js >= is && js <= ie){
                c.push_back(js);
                c.push_back(je);
            }
        }
    }
    // write the vector c into a binary file and record the num of records
    int num = c.size();
    
    out.open("./database/C.dat", ios::out | ios::binary);
    out.write((char*)&num, sizeof(num));
    for(int i = 0; i < num; i++){
        int temp = c[i];
        out.write((char*)&c[i], sizeof(int));
    }
    out.close();
    // read from the binary file and output on the screen
    ifstream in;
    in.open("./database/C.dat", ios::in | ios::binary);
    int s = 0;
    in.read((char*)&s, sizeof(s));
    vector<string> res;
    for(int i = 0; i < s; i++){
        int temp = 0;
        in.read((char*)&temp, sizeof(temp));
        string r = to_string(temp) + ":00";
        res.push_back(r);
    }
    in.close();
    for(int i = 0; i < s/2; i+=2){
        cout << res[i] << "~" << res[i+1] << endl;
    }
    return 0;
}