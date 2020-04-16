#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node{
    T val;
    Node *next;
public:
    // Node() { val  next = NULL; }
    Node(T v) { val = v; next = NULL; }
    T get_val() { return val; }
    Node* get_pt() { return next; }
};

template <class T>
class List{
    int num;
    Node *head;
    Node *tail;
public:
    List() { num = 0; head = tail = NULL; }
    
};