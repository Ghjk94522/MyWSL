#include <bits/stdc++.h>
#define elif else if
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

void visit(node *root, int &max, int &second)
{
    if(root == NULL) return;
    if (root->height > max)
    {
        second = max;
        max = root->height;
    }
    elif (root->height > second)
    {
        second = root->height;
    }
    // cout << root->val << endl;
    visit(root->left, max, second);
    visit(root->right, max, second);
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
    int max = -1, second = -1;
    visit(root, max, second);
    cout << max << endl
         << max + second + 1 << endl;
    return 0;
}