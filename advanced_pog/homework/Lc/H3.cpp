#include <bits/stdc++.h>
using namespace std;

void *my_memcpy(void *dst, void *src, unsigned count)
{
    if(src == NULL && count != 0){
        throw(-1);
    }
    for(int i = 0; i < count; i++){
        if(src+i == dst) throw(-101);
    }
    for(int i = 0; i < count; i++){
        if(src == dst+i) throw(-1011);
    }
    for(int i = 0; i < count; i++){
        *(char *)dst = *(char *)src;
        dst = (char *)dst + 1;
        src = (char *)src + 1;
    }
    return dst;
}

int main(){
    int *p, *q;
    try{
        my_memcpy(p, q, 100);
    }
    catch(int a){
        switch(a){
            case -1:{
                cerr << "The src ptr cannot be NULL. ERROR(-1)\n";
                exit(-1);
            }; break;
            case -101:{
                cerr << "The two ptr cannot contain each other. ERROR(-101)\n";
                exit(-101);
            }; break;
            case -1011:{
                cerr << "The two ptr cannot contain each other. ERROR(-1011)\n";
                exit(-1011);
            }
        }
    }
    return 0;
}