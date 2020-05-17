#include<bits/stdc++.h>
using namespace std;

enum Color{
    WHITE, GRAY, BLACK
};

struct node{
    int num;
    int back;
    int discoverTime;
    Color color;
    vector<int> neighbour;
};

int mytime;
node *p = NULL;
vector<int> res;

int find_arti_point(node &q){
    q.color = GRAY;
    mytime++;
    q.discoverTime = mytime;
    q.back = q.discoverTime;
    for(int i = 0; i < q.neighbour.size(); i++){
        if(p[q.neighbour[i]].color == WHITE){
            p[q.neighbour[i]].back = find_arti_point(p[q.neighbour[i]]);
            if(p[q.neighbour[i]].back >= q.discoverTime) res.push_back(q.num);
            q.back = min(q.back, p[q.neighbour[i]].back);
        }
        else if (p[q.neighbour[i]].color == GRAY)
            q.back = min(q.back, p[q.neighbour[i]].discoverTime);
    }
    return q.back;
}

int main(){
    int n; cin >> n;
    p = new node[n];
    int i, j;
    for(int i = 0; i < n; i++){
        p[i].num = i;
        p[i].color = WHITE;
    }
    while(cin >> i >> j){
        p[i].neighbour.push_back(j);
        p[j].neighbour.push_back(i);
    }
    mytime = 0;

    return 0;
}