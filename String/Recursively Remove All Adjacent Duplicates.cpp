#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, res;
        cin >> str;
        int c = 1;
        while (c)
        {
            res = "";
            int n, i, j;
            n = str.length();
            map<int, int> m;
            m[0] = 1;
            j = 0;
            c = 0;
            for (i = 1; i < n; i++)
            {
                if (str[j] == str[i])
                {
                    m[j]++;
                }
                else
                {
                    j = i;
                    m[j]++;
                }
            }
            for (auto k : m)
            {
                if (k.second < 2)
                {
                    res += str[k.first];
                }
                else
                {
                    c++;
                }
            }
            str = res;
        }

        cout << res << endl;
    }

    return 0;
}
//code
