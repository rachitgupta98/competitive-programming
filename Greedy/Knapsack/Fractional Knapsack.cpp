#include <bits/stdc++.h>
using namespace std;

bool sort_in_rev(const pair<double, pair<int, int>> &a, const pair<double, pair<int, int>> &b)
{
    return (a.first > b.first);
}
int main()
{
    int n;
    cin >> n;
    int bagSize;
    cin >> bagSize;
    double profit = 0;
    vector<pair<double, pair<int, int>>> m;
    for (int i = 0; i < n; i++)
    {
        int p, w;
        double r;
        cin >> p >> w;
        r = p / w;
        m.push_back(make_pair(r, make_pair(p, w)));
    }
    sort(m.begin(), m.end(), sort_in_rev);
    // for(int i=0;i<n;i++){
    //     cout<<m[i].first<<" "<<m[i].second.first<<" "<<m[i].second.second<<"\n";
    // }
    int i;
    for (i = 0; i < n; i++)
    {
        if (bagSize > 0 && m[i].second.second <= bagSize)
        {
            bagSize -= m[i].second.second;
            profit += m[i].second.first;
        }
        else
        {
            break;
        }
    }
    if (bagSize > 0)
    {
        profit += m[i].second.first * ((double)bagSize / (double)m[i].second.second);
    }
    cout << "Maximum possible profit is :" << profit;
}