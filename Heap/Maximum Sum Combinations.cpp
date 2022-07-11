/* 

https://www.interviewbit.com/problems/maximum-sum-combinations/
 */
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

int main()
{
    RW;
    IRON_MAN;
    int n, c;
    cin >> n >> c;
    int A[n], B[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    sort(A, A + n, greater<int>());
    sort(B, B + n, greater<int>());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> sp;
    pq.push({A[0] + B[0], {0, 0}});
    sp.insert({0, 0});
    for (int i = 0; i < c; i++)
    {
        pair<int, pair<int, int>> tmp = pq.top();
        pq.pop();
        int sum = tmp.first;
        cout << sum << " ";
        int j = tmp.second.first;
        int k = tmp.second.second;

        int sum1 = A[j + 1] + B[k];
        pair<int, int> indexPair1 = make_pair(j + 1, k);
        if (sp.count(indexPair1) == 0)
        {
            pq.push({sum1, indexPair1});
            sp.insert(indexPair1);
        }

        int sum2 = A[j] + B[k + 1];
        pair<int, int> indexPair2 = make_pair(j, k + 1);
        if (sp.count(indexPair2) == 0)
        {
            pq.push({sum2, indexPair2});
            sp.insert(indexPair2);
        }
    }

    return 0;
}