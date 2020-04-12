#include <bits/stdc++.h>
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
    if (prel > prer || inl > inr)
        return NULL;
    int k = inl;
    while (r[k] != p[prel])
        k++;
    node *root = new node;
    root->height = height;
    root->val = p[prel];
    root->left = prein2tree(prel+1, prel+k-inl, inl, k-1, height+1, p, r);
    root->right = prein2tree(prel+k-inl+1, prer, k+1, inr, height+1, p, r);
    return root;
}

int main()
{
    return 0;
}