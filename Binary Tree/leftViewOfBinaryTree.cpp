//left view of binary tree
// time complexity  o(n), where n is the number of nodes

//question link https://www.geeksforgeeks.org/print-left-view-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void leftview(node *temp)
{
    if (temp == NULL)
        return;
    queue<node *> q;
    q.push(temp);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {

            node *p = q.front();
            q.pop();
            if (i == 1)
                cout << p->data << " ";
            if (p->left != NULL)
            {
                q.push(p->left);
            }
            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }
}

int main()
{

    node *root = new node(10);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(8);
    root->right->right = new node(15);
    root->right->left = new node(12);
    root->right->right->left = new node(14);

    leftview(root);
    return 0;
}