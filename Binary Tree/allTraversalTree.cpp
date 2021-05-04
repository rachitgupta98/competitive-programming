//inorder, preorder(DFS), levelorder(bfs)
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

node *insertNode(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    else if (root->left == NULL)
    {
        root->left = new node(d);
    }
    else if (root->right == NULL)
    {
        root->right = new node(d);
    }
    else if (root->left != NULL)
    {
        insertNode(root->left, d);
    }
    else if (root->right != NULL)
    {
        insertNode(root->right, d);
    }
    return root;
}

void inorder(node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void levelorder(node *temp)
{
    if (temp == NULL)
        return;
    queue<node *> q;
    q.push(temp);
    while (!q.empty())
    {
        node *p = q.front();
        cout << p->data << " ";
        q.pop();
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

void preorder(node *temp)
{
    if (temp == NULL)
        return;
    stack<node *> s;
    s.push(temp);
    while (!s.empty())
    {
        node *p = s.top();
        cout << p->data << " ";
        s.pop();
        if (p->right)
        {
            s.push(p->right);
        }
        if (p->left)
        {
            s.push(p->left);
        }
    }
}
int main()
{

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);
    root->right->left = new node(1);
    inorder(root);
    cout << "\n";
    levelorder(root);
    cout << "\n";
    preorder(root);
    return 0;
}