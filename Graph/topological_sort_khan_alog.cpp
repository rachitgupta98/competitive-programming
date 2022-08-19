

#include <bits/stdc++.h>
using namespace std;

#define RW                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define IRON_MAN                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
vector<int> topSort(vector<int> adj[], int V)
{
    int indegree[V] = {0};
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x] = indegree[x] + 1;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push({i, 0});
        }
    }

    vector<int> order(V);
    int index = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int degree = q.front().second;
        order[index++] = node;
        q.pop();
        for (auto x : adj[node])
        {
            indegree[x] = indegree[x] - 1;
            if (indegree[x] == 0)
            {
                q.push({x, 0});
            }
        }
    }
    if (index != V)
    {
        return vector<int>{};
    }
    return order;
}

void addEdges(vector<int> v[], int s, int e)
{
    v[s].push_back(e);
}

int main()
{
    RW;
    IRON_MAN;
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> v[vertex];
    for (int i = 0; i < edges; i++)
    {
        int p, q;
        cin >> p >> q;
        addEdges(v, p, q);
    }
    vector<int> topOrdering = topSort(v, vertex);
    for (int i = 0; i < vertex; i++)
    {
        cout << topOrdering[i] << " ";
    }
    return 0;
}