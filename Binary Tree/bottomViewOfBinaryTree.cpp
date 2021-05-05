#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data, hd;
    node *left, *right;
    node(int d)
    {
        data = d;
        hd = INT_MAX;
        left = NULL;
        right = NULL;
    }
};

void bottomView(node *temp)
{
    if (temp == NULL)
        return;
    queue<node *> q;
    q.push(temp);
    temp->hd = 0;
    map<int, int> m;
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        m[p->hd] = p->data;

        if (p->left != NULL)
        {
            p->left->hd = p->hd - 1;
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            p->right->hd = p->hd + 1;
            q.push(p->right);
        }
    }
    for (auto x : m)
    {
        cout << x.second << " ";
    }
}

int main()
{

    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(25);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    bottomView(root);
    return 0;
}