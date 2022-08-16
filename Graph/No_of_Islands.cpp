//Problem link https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
//Time Complexity NxM

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the number of islands.
    void dfs(vector<vector<int>> &vis, vector<vector<char>> &grid, int row, int col, int drow[], int dcol[])
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
            {
                dfs(vis, grid, nrow, ncol, drow, dcol);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int drow[] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int dcol[] = {0, 1, 0, -1, -1, -1, 1, 1};
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char x = grid[i][j];
                if (x == '1' && !vis[i][j])
                {
                    c++;
                    dfs(vis, grid, i, j, drow, dcol);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends