#include <bits/stdc++.h>
#include "../include/common.h"
// #define N 10010
using namespace std;

struct node
{
    int val;
    int height;
    node *left;
    node *right;
};

node *prein2tree(int prel, int prer, int inl, int inr,
                 int height, vector<int> p, vector<int> r)
{
    if (prel > prer)
        return NULL;
    int k = inl;
    while (r[k] != p[prel])
        k++;
    node *root = new node;
    root->height = height;
    root->val = p[prel];
    root->left = prein2tree(prel + 1, prel + k - inl, inl, k - 1, height + 1, p, r);
    root->right = prein2tree(prel + k - inl + 1, prer, k + 1, inr, height + 1, p, r);
    return root;
}

int head[N] = {0};
int ver[N] = {0};
int Next[N] = {0};
int edge[N] = {0};
bool v[N];
int tot;

// the dp to calculate the d of the tree
void add(int x, int y, int z){
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}

int ans;
int d[N] = {0};

void dp(int x){
    v[x] = true;
    for(int i = head[x]; i; i = Next[i]){
        int y = ver[i];
        if(v[y]) continue;
        dp(y);
        if(d[x] + d[y] + edge[i] > ans) ans = d[x] + d[y] + edge[i];
        if(d[y] + edge[i] > d[x]) d[x] = d[y] + edge[i];
    }
}

void visit(node *root, int &max)
{
    if (root == NULL)
        return;
    if (root->height > max)
        max = root->height;
    // cout << root->val << endl;
    if(root->left != NULL){
        add(root->val, root->left->val, 1);
        add(root->left->val, root->val, 1);
        visit(root->left, max);
    }
    if(root->right != NULL){
        add(root->val, root->right->val, 1);
        add(root->right->val, root->val, 1);
        visit(root->right, max);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> p, r;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        r.push_back(temp);
    }
    node *root = prein2tree(0, p.size() - 1, 0, r.size() - 1, 0, p, r);
    int max = -1;
    visit(root, max);
    int d = -1;
    tot = 0; ans = 0;
    for(int i = 0; i <= n; i++) v[i] = false;
    dp(1);
    cout << max << endl
         << ans << endl;
    return 0;
}