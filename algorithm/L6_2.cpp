#include<bits/stdc++.h>
using namespace std;

#define __DFS__
#define maxNum 200000

struct Edge{
    int from;
    int to;
    // int weight;
    // Edge (int f, int t, int w): from(f), to(t), weight(w) {}
};

vector<int> G[maxNum];
vector<Edge> edges;
typedef vector<int>::iterator it_t;

int num_left;
int num_right;

int matching[maxNum];
int check[maxNum];

// The version of dfs

#ifdef __DFS__

bool dfs(int u){
    for(it_t i = G[u].begin(); i != G[u].end(); i++){
        int v = edges[*i].to;
        if(!check[v]){
            check[v] = true;
            if(matching[v] == -1 || dfs(matching[v])){
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian(){
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for(int u = 0; u < num_left; u++){
        if(matching[u] == -1){
            memset(check, 0, sizeof(check));
            if(dfs(u))
                ans++;
        }
    }
    return ans;
}

#endif

// The version of bfs

#ifdef __BFS__

queue<int> Q;
int prev[];
int hungarian(){
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    memset(check, -1, sizeof(check));
    for(int i = 0; i < num_left; i++){
        if(matching[i] == -1){
            while(!Q.empty())
                Q.pop();
            Q.push(1);
            prev[i] = -1;
            bool flag = false;
            while(!Q.empty() && !flag){
                int u = Q.front();
                for(it_t ix = G[u].begin(); ix != G[u].end(); i++){
                    int v = edges[*ix].to;
                    if(check[v] != i){
                        check[v] = i;
                        Q.push(matching[v]);
                        if(matching[v] >= 0)
                            prev[matching[v]] = u;
                        else{
                            flag = true;
                            int d = u;
                            int e = v;
                            while(d != -1){
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if(matching[i] != -1) ans++;
        }
    }
    return ans;
}

#endif

// Main function

Edge p[200000];

int main(){
    string temp;
    int n = 0;
    while(getline(cin, temp)){
        istringstream in(temp);
        int start = 0;
        in >> start;
        int to = 0;
        while(in >> to){
            G[start].push_back(to);
            Edge t;
            t.from = start;
            t.to = to;
            edges.push_back(t);
        }
    }
    int ans = hungarian();
    cout << ans;
    return 0;
}

// a method for getline
#ifdef __GETLINE__
    
    string s;
	int n=0;
	while (getline(cin, s))
	{
		n++;
		istringstream in(s);
		int id;
		int temp = 0;
		in >> id;
		while (in >> temp)
		{
			G[id].push_back(temp);
			G[temp].push_back(id);
		}
	}

#endif