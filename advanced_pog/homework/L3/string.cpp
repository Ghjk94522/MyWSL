#include<bits/stdc++.h>
using namespace std;

class mystring{
    char *s;
    int length;
public:
    mystring(){
        s = NULL;
        length = 0;
    }
    mystring(char *str){
        length = 0;
        for(int i = 0; str[i]; i++) length++;
        s = new char[length+1];
        for(int i = 0; i < length; i++)
            s[i] = str[i];
        s[length] = '\0';
    }
    ~mystring(){
        if(s != NULL){
            delete[] s;
            s = NULL;
            length = 0;
        }
    }
    int length(){
        return length;
    }
    int stradd(const mystring &a, const mystring &b, mystring &d){};
};

int mystring:: stradd(const mystring &a, const mystring &b, mystring &d){
    if(d.s != NULL){
        d.~mystring();
    }
    
}