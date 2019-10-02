#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    stack<char> p;
    if (s.size() % 2 != 0)
    {
        cout << "not balanced"
             << "\n";
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {
                p.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                if (p.empty())
                {
                    p.push('a'); // push anything so that stack is not empty and give output not balanced
                    break;
                }
                else if (s[i] - p.top() > 0 && s[i] - p.top() < 3) // ascii value difference between brackets is not more than 2 ,()->40,41,{}->123,125,[]->91,93 respectively
                {
                    p.pop();
                }
                else
                {
                    break;
                }
            }
        }

        if (p.empty())
        {
            cout << "balanced"
                 << "\n";
        }
        else
        {
            cout << "not balanced"
                 << "\n";
        }
    }

    return 0;
}