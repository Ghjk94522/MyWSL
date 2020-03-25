#include<bits/stdc++.h>
#include<ctime>
using namespace std;

class A{
public:
    void f1(){ cout << "This func1.\n"; };
    void f2(){ cout << "This func2.\n"; };
    void f3(){ cout << "This func3.\n"; };
    void f4(){ cout << "This func4.\n"; };
};

class B{
    string lastTime;
    A *a;
public:
    B(){
        lastTime = "";
        a = NULL;
    }
    B(A *p){
        a = p;
        lastTime = "";
    }
    ~B(){
        lastTime = "";
        a = NULL;
    }
    A* operator -> (){
        time_t nowTime = time(NULL);
        lastTime = asctime(localtime(&nowTime));
        return a;
    }
    string string_access(){ return lastTime; }
};

void visit(const B& b){
    cout << "Which funciton da you want to visit?(1, 2, 3, 4)";
    int i; cin >> i;
    switch (i) {
        case 1 : {
            b->f1();
        }; break;
        case 2 : {
            b->f2();
        }; break;
        case 3 : {
            b->f3();
        }; break;
        case 4 : {
            b->f4();
        }; break;
        default : {
            cerr << "Input Error!\n";
            exit(-1);
        }
    }
}

int main(){
    A a;
    B b(&a);
    visit(b);
    cout << b.string_access() << endl;
    return 0;
}