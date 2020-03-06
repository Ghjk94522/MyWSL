#include<bits/stdc++.h>
using namespace std;

class single{
    static int count;
public:
    single(){
        count++;
    }
    ~single(){
        count--;
    }
    friend single* creat();
};

single *root = NULL;

single* creat(){
    if(single:: count == 0){
        single *p = new single;
        root = p;
        return p;
    }
    else{
        return root;
    }
}

/*
合理运用C++提供的各种机制，定义一个类Single，使得程序中只能创建一个该类的对象。
当试图创建该类的第二个对象时，返回第一个对象的指针。请注意运用可能的机制保障该类对象的唯一性。
*/