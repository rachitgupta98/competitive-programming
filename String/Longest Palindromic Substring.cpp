// https://leetcode.com/problems/longest-palindromic-substring/

//Time Complexity o(n^2)
// Space Complexity o(1);
//Approach 4: Expand Around Center

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcbabac";
    if (s.empty())
        cout << "";
    if (s.size() == 1)
        cout << s;
    int size = s.size();
    int L, R, len = -1;
    int pos = 0;
    char k;
    for (int i = 0; i < size; i++)
    {
        L = R = i;
        k = s[R];
        while (R + 1 <= size && (k == s[R + 1]))
        {
            R++;
        }
        i = R;

        while (R + 1 <= size && L - 1 >= 0 && (s[R + 1] == s[L - 1]))
        {
            R++;
            L--;
        }

        if (len < R - L + 1)
        {
            len = R - L + 1;
            pos = L;
        }
    }

    cout << s.substr(pos, len);
}