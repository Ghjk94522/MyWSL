#include<list>
#include<stack>
#include<limits.h>
#include<stdio.h>
using namespace std;

// #define -0x3f3f3f3f INT_MIN

// The new version will try a large static array
// replace the dynamic new array

class AdjListNode
{
    int v; // the neighbour
    int weight; 

public:
    AdjListNode(int V, int w)
    {
        v = V;
        weight = w;
    }
    int get_v() { return v; }
    int get_w() { return weight; }
};

class Graph
{
    int v; // the num of nodes
    list<AdjListNode> adj[100000];
    void topologicalSortUtill(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int v);
    void addEdge(int u, int v, int weight);
    void longestPath(int s);
};

Graph::Graph(int v)
{
    this->v = v;
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtill(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.get_v()])
            topologicalSortUtill(node.get_v(), visited, Stack);
    }
    Stack.push(v);
}

void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[v];
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            topologicalSortUtill(i, visited, Stack);
    }
    for (int i = 0; i < v; i++)
        dist[i] = -0x3f3f3f3f;
    dist[s] = 0;
    while (Stack.empty() == false)
    {
        int u = Stack.top();
        Stack.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != -0x3f3f3f3f)
        {
            for (i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (dist[i->get_v()] < dist[u] + i->get_w())
                    dist[i->get_v()] = dist[u] + i->get_w();
            }
        }
    }
    for (int i = 1; i < v; i++)
        printf("%d ", dist[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    Graph g(n);
    int x, y, z;
    while(3 == scanf("%d %d %d", &x, &y, &z)){
        g.addEdge(x, y, z);
    }
    g.longestPath(0);
    return 0;
}