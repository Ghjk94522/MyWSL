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

struct edge{
    int a;
    int b;
};

int mytime;
node *p = NULL;
vector<int> res;
vector<edge> rlt;

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
    q.color = BLACK;
    return q.back;
}

void find_bridge(node &q){
    q.color = GRAY;
    mytime++;
    q.discoverTime = mytime;
    q.back = q.discoverTime;
    for(int i = 0; i < q.neighbour.size(); i++){
        if(p[q.neighbour[i]].color == WHITE){
            find_bridge(p[q.neighbour[i]]);
            q.back = min(q.back, p[q.neighbour[i]].back);
            if(p[q.neighbour[i]].back > q.discoverTime){
                edge temp;
                temp.a = min(q.num, p[q.neighbour[i]].num);
                temp.b = max(q.num, p[q.neighbour[i]].num);
                rlt.push_back(temp);
            }
        }
        else if(p[q.neighbour[i]].color == GRAY)
            q.back = min(q.back, p[q.neighbour[i]].back);
    }
}

bool cmp(edge a, edge b){
    if(a.a < b.a) return true;
    else if(a.a > b.a) return false;
    else if(a.b < b.b) return true;
    else return false;
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
    find_arti_point(p[0]);
    for(int i = 0; i < n; i++) p[i].color = WHITE;
    find_bridge(p[0]);
    sort(res.begin(), res.end());
    sort(rlt.begin(), rlt.end(), cmp);
    for(int i = 0; i < res.size(); i++) cout << res[i] << "\n";
    for(int i = 0; i < rlt.size(); i++) cout << rlt[i].a << " " << rlt[i].b << "\n";
    return 0;
}