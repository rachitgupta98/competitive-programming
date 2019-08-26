//https://leetcode.com/problems/longest-substring-without-repeating-characters/

/* Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
 */

//code_01  TIME_COMPLEXITY  o(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    set<char> k;
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < n && j < n)
    {
        if (k.count(s[j]))
        {
            k.erase(s[i]);
            i++;
        }
        else
        {
            k.insert(s[j]);
            j++;
            res = max(res, j - i);
        }
    }

    cout << res;

    return 0;
}

//more efficient way in o(n)
//code_02

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    vector<int> array(256, -1);

    int maxLen = 0, s_index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        s_index = max(s_index, array[s[i]]);

        array[s[i]] = i;

        maxLen = max(maxLen, i - s_index);
    }

    cout << maxLen;

    return 0;
}