#include<bits/stdc++.h>
using namespace std;

class Str{
    char *s;
    int len;
public:
    Str(){
        s = NULL;
        len = 0;
    }
    Str(char *p, int l){
        s = p;
        len = l;
    }
    ~Str(){
        delete[] s;
        s = NULL;
        len = 0;
    }
    void output();
    char& operator [](int i); 
};

void Str:: output(){
    cout << *s << endl;
}

char& Str::operator [](int i){
    if(i >= len){
        cerr << "Input index is larger than the length of the string.\nThis may cause segment fault.Check and input index \
                    again.\n";
        exit(-1);
    }
    return s[i];
}