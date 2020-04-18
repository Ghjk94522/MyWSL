#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
    T val;
    Node *next;

public:
    // Node() { val  next = NULL; }
    Node(T v)
    {
        val = v;
        next = NULL;
    }
    T get_val() { return val; }
    Node *&get_pt() { return next; }
};

template <class T>
class List
{
    int num;
    Node<T> *head;
    Node<T> *tail;

public:
    List()
    {
        num = 0;
        head = tail = NULL;
    }
    void add(T dat);
    void display();
    ~List()
    {
        Node<T> *p = head;
        if (num != 0)
        {
            while (p != NULL)
            {
                Node<T> *q = p;
                p = p->get_pt();
                delete q;
            }
            head = tail = NULL;
            num = 0;
        }
    }
};

template <class T>
void List<T>::add(T dat)
{
    Node<T> *p = new Node<T>(dat);
    if (head == NULL)
    {
        head = p;
        tail = p;
        p->get_pt() = NULL;
    }
    else
    {
        tail->get_pt() = p;
        p->get_pt() = NULL;
        tail = p;
    }
    num++;
}

template <class T>
void List<T>::display()
{
    Node<T> *p = head;
    for(int i = 0; i < num; i++){
        cout << p->get_val() << endl;
        p = p->get_pt();
    }
}

int main(){
    List<int> li;
    List<double> ld;
    List<string> ls;
    for(int i = 0; i < 3; i++){
        int temp; cin >> temp;
        li.add(temp);
    }
    printf("The int list is : \n");
    li.display();
    for(int i = 0; i < 3; i++){
        double temp; cin >> temp;
        ld.add(temp);
    }
    printf("The double list is : \n");
    ld.display();
    for(int i = 0; i < 3; i++){
        string temp; cin >> temp;
        ls.add(temp);
    }
    printf("The string list is : \n");
    ls.display();
    return 0;
}