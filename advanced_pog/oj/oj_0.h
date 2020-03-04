#include <string>
using namespace std;

class Goods{
private:
    string name;
    int nums;
public:
    Goods(string name,int nums);
    void show();
    string check_name();
    void set_num(int num);
    int check_num();
    void set_property(string newN, int newI);
    ~Goods();
};


class GoodsList{
private:
    struct Node{
        Goods* goods;
        Node* next;
    } *list;
public:
    GoodsList();
    void insert(Goods* goods);
    void remove(string name, int nums);
    void show();
    void sort();
    int count();
    void clear();
    ~GoodsList();
    inline void swap_node(Node *p, Node *q);
};
