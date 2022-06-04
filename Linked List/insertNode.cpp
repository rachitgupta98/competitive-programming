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
















#include <bits/stdc++.h> 
#include <stack>
using namespace std; 

struct node{
    int data;
    node *next;
};  
node *A =NULL;

void insertAtFront(int n){
    node *temp = new node();
    temp->data= n;
    temp->next = A;
    A = temp;
}
void insertAtBack(int d){
    node *temp = new node();
    temp->data = d;
    temp->next = NULL;
    node *h = A;
    while(h->next!=NULL){
        h=h->next;
    }
    h->next = temp;
    
}
void insertAtPosition(int s, int p){
    node *temp = new node();
    temp->data = s;
    temp->next = NULL;
    node *h = A;
    for(int i=0;i<p-2;i++){
        h=h->next;
    }
    temp->next=h->next;
    h->next=temp;
    
}
  void display(){
      node *h;
      h=A;
      while(h!=NULL){
          cout<<h->data<<endl;
           h=h->next;
      }
     
  }
  void deleteNode( int p){
      node *h = A;
      for(int i=0;i<p-2;i++){
          h=h->next;
      }
      h->next = h->next->next;
      
      
  }
  void deteleAtFront(){
      node *temp = A;
      A=A->next;
      free(temp);
       
  }
  void reverse(){
      
      stack<struct node*>S;
      node *temp = A;
      while(temp!=NULL){
          S.push(temp);
          temp = temp->next;
      }
      temp = S.top();
      A = temp;
      S.pop();
      while(!S.empty()){
          temp->next=S.top();
          S.pop();
          temp = temp->next;
      }
      temp->next = NULL;
      
  }
  void reverse2(){
      node *curr,*prev,*n;
      curr=A;
      prev=NULL;
      while(curr!=NULL){
          n=curr->next;
          curr->next = prev;
          prev = curr;
          curr = n;
      }
      A=prev;
  }
  void reverseRecursion(node *p){
      if(p->next==NULL){
          A=p;
          return;
      }
      reverseRecursion(p->next);
      node *h = p->next;
      h->next=p;
      p->next=NULL;
  }
int main(){
    int t,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x;
        insertAtFront(x);
        //insertAtBack(x);
    }
    //  insertAtBack(20);
    //  insertAtPosition(45,3);
    // insertAtPosition(45,7);
    // deleteNode(8);
    //deteleAtFront();
    //   reverse2();
    //reverseRecursion(A);
    display();
   
    
}