#include <bits/stdc++.h>
using namespace std;

//class for creating node
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// inserting node at the end of linked list
Node *insertNodeAtBack(Node *root, int val)
{
    Node *temp = new Node(val);
    Node *loop = root;
    while (loop->next)
    {
        loop = loop->next;
    }
    loop->next = temp;
    return root;
}

// inserting node at the start of linked list
Node *insertNodeAtFront(Node *root, int val)
{
    Node *temp = new Node(val);
    temp->next = root;
    root = temp;
    return root;
}

// inserting node at the specific position of linked list
Node *insertNodeAtPosition(Node *root, int val, int pos)
{
    Node *temp = new Node(val);
    if (pos <= 0)
    {
        cout << "position should greater than 0"
             << "\n";
        return root;
    }
    if (pos == 1)
    {
        temp->next = root;
        root = temp;
        return root;
    }
    Node *loop = root;

    // here we try to reach to a node just before the node which is at position 'pos'
    for (int i = 1; i < pos - 1; i++)
    {
        loop = loop->next;
    }
    temp->next = loop->next;
    loop->next = temp;
    return root;
}

//displaying the linked list
void printLinkedList(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

int main()
{
    Node *root = new Node(1);
    for (int i = 2; i < 7; i++)
    {
        root = insertNodeAtBack(root, i);
    }
    root = insertNodeAtFront(root, 7);
    root = insertNodeAtPosition(root, 8, 0);
    printLinkedList(root);
    return 0;
}