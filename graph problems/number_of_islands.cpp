#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != 'L')
    {
        return;
    }
    visited[i][j] = true;
    dfs(i + 1, j, grid, visited, n, m); // right
    dfs(i - 1, j, grid, visited, n, m); // left
    dfs(i, j + 1, grid, visited, n, m); // top
    dfs(i, j - 1, grid, visited, n, m); // bottom
}
int countIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'L' && !visited[i][j])
            {

                dfs(i, j, grid, visited, n, m);
                islands++;
            }
        }
    }
    return islands;
}
int main()
{
    vector<vector<char>> grid = {
        {'L', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}};
   /* vector<vector<char>> gridy = {
        {'W', 'L', 'L', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'L', 'L', 'W', 'L', 'W'}};*/

    // printing the number of islands
    cout << countIslands(grid) << endl;

    return 0;
}
//https://www.geeksforgeeks.org/dsa/top-50-graph-coding-problems-for-interviews/