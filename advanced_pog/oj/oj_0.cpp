#include<bits/stdc++.h>
#include"oj_0.h"
#define FOR_TEST
using namespace std;

Goods:: Goods(string name,int nums){
    this->name = name;
    this->nums = nums;
}

Goods:: ~Goods(){}

void Goods:: show(){
    printf("%s.%d\n", name.c_str(), nums);
}

string Goods:: check_name(){
    return name;
}

void Goods:: set_num(int num){
    nums += num;
}

int Goods:: check_num(){
    return nums;
}

GoodsList:: GoodsList(){
    list = NULL;
}

GoodsList:: ~GoodsList(){}

int GoodsList:: count(){
    int ans = 0;
    for(Node *p = list; p != NULL; p = p->next) ans++;
    return ans;
}

void GoodsList:: insert(Goods* goods){
    for(Node *p = list; p != NULL; p = p->next){
        if(goods->check_name() == p->goods->check_name()){
            p->goods->set_num(goods->check_num());
            return;
        }
    }
    if(list == NULL){
        Node *q = new Node;
        q->goods = goods;
        q->next = NULL;
        list = q;
    }
    else{
        Node *p = NULL;
        for(p = list; p->next != NULL; p = p->next);
        Node *q = new Node;
        q->goods = goods;
        q->next = NULL;
        p->next = q;
    }
}

void GoodsList:: remove(string name, int nums){
    for(Node *p = list; p != NULL; p = p->next){
        if(p->goods->check_name() != name)
            continue;
        else{
            if(p->goods->check_num() < nums){
                cout << "Not enough goods!\n";
                return;
            }
            else{
                p->goods->set_num(-nums);
                if(p->goods->check_num() == 0){
                    Node *q = list;
                    if(q == p){
                        if(p->next == NULL){
                            delete p;
                            list = NULL;
                            return;
                        }
                        list = list->next;
                        delete q;
                        return;
                    }
                    for(; q->next != p; q = q->next);
                    q->next = p->next;
                    delete p;
                    return;
                }
                return;
            }
        }
    }
    return;
}

void GoodsList:: show(){
    for(Node *p = list; p != NULL; p = p->next){
        printf("%s.%d ", p->goods->check_name().c_str(), p->goods->check_num());
    }
    cout << endl;
}

void Goods:: set_property(string newN, int newI){
    name = newN;
    nums = newI;
}

inline void GoodsList:: swap_node(Node *p, Node *q){
    string temps = p->goods->check_name();
    int tempi = p->goods->check_num();
    p->goods->set_property(q->goods->check_name(), q->goods->check_num());
    q->goods->set_property(temps, tempi);
}

void GoodsList:: sort(){
    for(Node *p = list; p->next != NULL; p = p->next){
        for(Node *q = p->next; q != NULL; q = q->next){
            if(q->goods->check_num() > p->goods->check_num()){
                swap_node(p, q);
            }
        }
    }
}

void GoodsList:: clear(){
    Node *p = list;
    while(p != NULL){
        Node *q = p;
        p = p->next;
        delete q;
    }
    list = NULL;
}

#ifdef FOR_TEST

int main(){
    GoodsList list;
    Goods *good1 = new Goods("apple", 500);
    Goods *good2 = new Goods("pear", 100);
    Goods *good3 = new Goods("peach", 150);
    Goods *good4 = new Goods("pear", 150);
    list.insert(good1);
    list.insert(good2);
    list.insert(good3);
    list.insert(good4);
    list.show();
    list.remove("apple", 100);
    list.show();
    list.remove("apple", 1000);
    list.remove("peach", 150);
    list.show();
    cout << list.count() << endl;
    list.sort();
    list.show();
    list.clear();
    cout << list.count() << endl;
    return 0;
}

#endif