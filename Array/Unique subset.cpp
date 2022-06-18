#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i, j, n) for (int i = j; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long int lli;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef map<int, int> MPII;
typedef set<int> SETI;

const int mod = 1e9 + 7;
#define RW                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define IRON_MAN                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
vector<int> ans;
int sum = 0;
void subsetSum(vector<int> &a, int s, int len, set<vector<int>> &sp, vector<int> &vp)
{
    if (s == len)
    {
        sort(all(vp));
        sp.insert(vp);
        return;
    }
    vp.push_back(a[s]);
    subsetSum(a, s + 1, len, sp, vp);
    vp.pop_back();
    subsetSum(a, s + 1, len, sp, vp);
}

int main()
{
    RW;
    IRON_MAN;
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.pb(t);
    }
    set<vector<int>> s;
    vector<int> ves;

    subsetSum(v, 0, n, s, ves);
    for (auto it : s)
    {
        for (auto k : it)
        {
            cout << k << " ";
        }
        cout << "\n";
    }
    return 0;
}