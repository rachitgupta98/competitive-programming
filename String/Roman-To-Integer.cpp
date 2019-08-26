//https://leetcode.com/problems/roman-to-integer/

/* 
Example 1:
        Input: "III"
        Output: 3
Example 2:
        Input: "IV"
        Output: 4
Example 3:
        Input: "IX"
        Output: 9 
*/

// cpp code

#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{

    string s;
    cin >> s;
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
        {
            ans += m[s[i + 1]] - m[s[i]];
            i++;
            continue;
        }
        else if (s[i] == 'I' && (s[i + 1] != 'V' || s[i + 1] != 'X'))
        {
            ans += m[s[i]];
            continue;
        }
        if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
        {
            ans += m[s[i + 1]] - m[s[i]];
            i++;
            continue;
        }
        else if (s[i] == 'X' && (s[i + 1] != 'L' || s[i + 1] != 'C'))
        {
            ans += m[s[i]];
            continue;
        }
        if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
        {
            ans += m[s[i + 1]] - m[s[i]];
            i++;
            continue;
        }
        else if (s[i] == 'C' && (s[i + 1] != 'D' || s[i + 1] != 'M'))
        {
            ans += m[s[i]];
            continue;
        }
        if (s[i] == 'V' || s[i] == 'L' || s[i] == 'D' || s[i] == 'M')
        {
            ans += m[s[i]];
            continue;
        }
    }
    cout << ans;
    return 0;
}