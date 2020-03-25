#include<bits/stdc++.h>
#define FOR_TEST
using namespace std;

class fib{
    int pre;
    int now;
    int next;
public:
    fib(){
        pre = 1;
        now = 1;
        next = 1;
    }
    fib(int x){
        if (x == 1){
            pre = 1; now = 1; next = 1;
        }
        else if(x == 2){
            pre = 1; now = 1; next = 2;
        }
        else{
            pre = 1; now = 1; next = 2;
            for(int i = 2; i < x; i++){
                pre = now; now = next;
                next = pre + now;
            }
        }
    }
    int operator () (int x){
        pre = 1; now = 1; next = 2;
        for(int i = 2; i < x; i++){
            pre = now; now = next;
            next = pre + now;
        }
        return now;
    }
};

#ifdef FOR_TEST
int main(){
    fib test(3);
    cout << test(4) << endl;
    fib test2;
    cout << test2(8) << endl;
    cout << test(6) << endl;
    return 0;
}
#endif