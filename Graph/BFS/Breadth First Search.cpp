#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>> &v, int s, int e)
{
    v[s].push_back(e);
}

void BFS(vector<vector<int>> &v, int s)
{

    queue<int> q;
    vector<bool> visited(v.size(), false);
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();
        for (int i = 0; i < v[s].size(); i++)
        {
            if (visited[v[s][i]] == false)
            {
                q.push(v[s][i]);
                visited[v[s][i]] = true;
            }
        }
    }
}

int main()
{

    int vertex, edges, source;
    cin >> vertex >> edges >> source; //no of vertex,no of edges, source from where BFS to start
    vector<vector<int>> v(vertex + 1);
    for (int i = 0; i < edges; i++)
    {
        int p, q;
        cin >> p >> q;
        addEdges(v, p, q);
    }
    //   cout<<v[2][0];
    BFS(v, source);
    return 0;
}
