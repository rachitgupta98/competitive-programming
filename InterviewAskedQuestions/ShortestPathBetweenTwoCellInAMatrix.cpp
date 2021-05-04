#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/discuss/interview-question/1033264/amazon-oa-1-year-experienced-for-sde1
/*

Sample Input
1 0 0
1 0 0
1 9 1


find shortest path to reach at 9 from top left corner;

output - 3



*/

int main()
{

    int r, c;
    cin >> r >> c;
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int sr = 0, sc = 0;
    queue<int> rq, cq;

    int moves = 0;
    int nodesInQueue = 1;
    int nodeNextQueue = 0;

    bool end = false;
    bool vis[r * c][r * c] = {false};

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    rq.push(sr);
    cq.push(sc);
    vis[sr][sc] = true;

    while (!rq.empty())
    {
        int row = rq.front();
        int col = cq.front();
        rq.pop();
        cq.pop();
        if (a[row][col] == 9)
        {
            end = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int rr = row + dr[i];
            int cc = col + dc[i];
            if (rr < 0 || cc < 0)
                continue;
            if (rr >= r || cc >= c)
                continue;
            if (vis[rr][cc])
                continue;
            if (a[rr][cc] == 0)
                continue;

            rq.push(rr);
            cq.push(cc);
            vis[rr][cc] = true;
            nodeNextQueue++;
        }
        nodesInQueue--;
        if (nodesInQueue == 0)
        {
            nodesInQueue = nodeNextQueue;
            nodeNextQueue = 0;
            moves++;
        }
    }
    if (end)
    {
        cout << moves;
    }
    else
    {
        cout << -1;
    }

    return 0;
}