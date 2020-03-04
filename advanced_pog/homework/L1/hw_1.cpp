#include<bits/stdc++.h>
using namespace std;

/*
struct proc_queue{
    int val;
    proc_queue* right;
    // proc_queue* left;
} queue_1;

proc_queue *head = NULL, *tail = NULL;

int push_proc(int x){
    if(tail == NULL){
        proc_queue *p = new proc_queue;
        p->val = x;
        p->right = NULL;
        head = p;
        tail = p;
    }
    else{
        proc_queue *p = new proc_queue;
        if(p == NULL){
            cerr << "NO SPARE SPACE.\n";
            return -1;
        }
        p->val = x;
        p->right = NULL;
        tail->right = p;
        tail = p;
    }
    return 0;
}

int pop_proc(int &x){
    if(head == NULL){
        cerr << "THE QUEUE IS ALREADY EMPTY\n";
        return -1;
    }
    else if(head == tail){
        x = head->val;
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        proc_queue *q = head;
        head = head->right;
        x = q->val;
        delete q;
    }
    return 0;
}

// 操作系统，计网，高程
*/

/*
#define max_n 0x10086

class data_queue{
private:
    int a[max_n];
    int head, tail;
    int flag;
public:
    data_queue(){
        flag = 1;
        head = 0;
        tail = -1;
    };
    int push_data(int x);
    int pop_data(int &x);
};

int data_queue:: push_data(int x){
    if(tail == -1){
        a[0] = x;
        tail = 1;
    }
    else if(flag == 0){
        cerr << "NO SPARE SPACE.\n";
        return -1;
    }
    else{
        a[tail] = x;
        tail = (tail+1) % max_n;
        if(tail == head) flag = 0;
        if(flag == 2) flag = 1;
    }
    return 0;
}

int data_queue:: pop_data(int &x){
    if(tail == -1 || flag == 2){
        cerr << "THE QUEUE IS ALREADY EMPTY\n";
        return -1;
    }
    else{
        head = (head+1) % max_n;
        if(head == tail) flag = 2;
        if(flag == 0) flag = 1;
    }
    return 0;
}
*/

class data_queue{
    struct node{
        int val;
        node* right;
    } *head, *tail;
public:
    int push_data(int x);
    int pop_data(int &x);
    data_queue(){
        head = NULL;
        tail = NULL;
    };
};

int data_queue:: push_data(int x){
    if(tail == NULL){
        node *p = new node;
        p->val = x;
        p->right = NULL;
        head = p;
        tail = p;
    }
    else{
        node *p = new node;
        if(p == NULL){
            cerr << "NO SPARE SPACE.\n";
            return -1;
        }
        p->val = x;
        p->right = NULL;
        tail->right = p;
        tail = p;
    }
    return 0;
}

int data_queue:: pop_data(int &x){
    if(head == NULL){
        cerr << "THE QUEUE IS ALREADY EMPTY\n";
        return -1;
    }
    else if(head == tail){
        node *p = head;
        head = head->right;
        x = p->val;
        delete p;
        head = NULL;
        tail = NULL;
    }
    else{
        node *p = head;
        head = head->right;
        x = p->val;
        delete p;
    }
    return 0;
}