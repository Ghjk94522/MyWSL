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
    int get_length() const{
        return length;
    }
    friend int stradd(const mystring &a, const mystring &b, mystring &d);
    int print(){
        for(int i = 0; s[i]; i++)
            cout << s[i];
        return 0;
    }
};

int stradd(const mystring &a, const mystring &b, mystring &d){
    if(d.s != NULL){
        d.~mystring();
    }
    int newlength = a.get_length() + b.get_length();
    d = new char[newlength+1];
    int count = 0;
    for(int i = 0; a.s[i]; i++){
        d.s[count++] = a.s[i];
    }
    for(int i = 0; b.s[i]; i++){
        d.s[count++] = b.s[i];
    }
    d.s[newlength] = '\0';
    d.length = newlength;
    return newlength;
}

int main(){
    char a[] = "Hello World\n";
    char b[] = "Hello C++\n";
    mystring s1(a);
    mystring s2(b);
    s1.print();
    cout << "The length of the s1 is " << s1.get_length() << endl;
    s2.print();
    cout << "The length of the s2 is " << s2.get_length() << endl;
    mystring s;
    stradd(s1, s2, s);
    s.print();
    cout << "The length of the s is " << s.get_length() << endl;
    return 0;
}