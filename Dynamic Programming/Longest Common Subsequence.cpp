//Time Complexity is o(m*n);

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcdadfge";
    string b = "bdafe";
    int n = s.size();
    int m = b.size();
    int dp[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; //initialize 1st row & 1st col with value 0;
            else if (b[i - 1] == s[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[m][n] << "\n"; //print length of lcs

    string k = "";
    int p = m, q = n;
    while (p > 0 && q > 0)
    {
        if (dp[p - 1][q] == dp[p][q - 1])
        {
            k += s[q - 1];
            p--;
            q--;
        }
        else if (dp[p - 1][q] > dp[p][q - 1])
            p--;
        else
            q--;
    }
    reverse(k.begin(), k.end());
    cout << k; // print the lcs
    return 0;
}