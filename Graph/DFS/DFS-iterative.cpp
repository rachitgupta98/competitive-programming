#include <bits/stdc++.h>
using namespace std;
#define MAX 20000
void addEdges(vector<vector<int>> &v, int s, int e)
{
    v[s].push_back(e);
    v[e].push_back(s);
}

void DFS(vector<vector<int>> &v, int s)
{

    stack<int> q;
    vector<bool> visited(MAX, false);
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        s = q.top();
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
    vector<vector<int>> v(MAX);
    for (int i = 0; i < edges; i++)
    {
        int p, q;
        cin >> p >> q;
        addEdges(v, p, q);
    }
    //   cout<<v[2][0];
    DFS(v, source);
    return 0;
}
