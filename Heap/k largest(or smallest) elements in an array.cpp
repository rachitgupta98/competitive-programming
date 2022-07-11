/* 
https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

TC= creating max heap + deleting k elements
0 (n) + 0(klogn)

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

void heapify(int a[], int i, int n)
{
    int maxValIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l <= n && a[l] > a[maxValIndex])
    {
        maxValIndex = l;
    }
    if (r <= n && a[r] > a[maxValIndex])
    {
        maxValIndex = r;
    }
    if (maxValIndex != i)
    {
        swap(a[i], a[maxValIndex]);
        heapify(a, maxValIndex, n);
    }
}

int main()
{
    RW;
    IRON_MAN;
    int n, k;
    cin >> n >> k;
    int a[n];
    // 1 2 3 4 5 6 7
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    for (int i = n - 1; i > (n - 1) - k; i--)
    {
        swap(a[0], a[i]);
        cout << a[i] << " ";
        heapify(a, 0, n - 1);
    }
    return 0;
}