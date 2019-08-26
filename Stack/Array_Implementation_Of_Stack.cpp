//Array Implementation Of Stack using Structure

#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

struct dum_stack
{
    int top;
    int x;
    int v[MAX_SIZE];
    void input()
    {
        cin >> x;
    }
    void push()
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "overflow condition"
                 << "\n";
            return;
        }
        v[++top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Nothing remain to pop"
                 << "\n";
            return;
        }
        top -= 1;
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << v[i];
        }
        cout << endl;
    }
};

int main()
{

    dum_stack b;
    b.top = -1;
    int n; //no of element you want to push
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        b.input(); // get the input
        b.push();  // push work same as stack;
    }
    b.display();
    b.pop();
    b.display();
    return 0;
}