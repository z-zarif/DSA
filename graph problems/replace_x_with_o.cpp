#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void dfsRecur(int i, int j, vector<vector<char>> &grid, int n, int m, int prevV, int newV)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != prevV)
    {
        return;
    }

    grid[i][j] = 'O';
    dfsRecur(i + 1, j, grid, n, m, prevV, newV);
    dfsRecur(i - 1, j, grid, n, m, prevV, newV);
    dfsRecur(i, j + 1, grid, n, m, prevV, newV);
    dfsRecur(i, j - 1, grid, n, m, prevV, newV);
}
void fill(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O')
                grid[i][j] = '-';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '-')
        {
            dfsRecur(i, 0, grid, n, m, '-', 'O');
        }

        if (grid[i][m - 1] == '-')
        {
            dfsRecur(i, m - 1, grid, n, m, '-', 'O');
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i])
        {
            dfsRecur(0, i, grid, n, m, '-', 'O');
        }
        if (grid[n - 1][i])
        {
            dfsRecur(n - 1, i, grid, n, m, '-', 'O');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '-')
                grid[i][j] = 'X';
        }
    }
}
int main()
{
    vector<vector<char>> grid = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };

    fill(grid);

    for (auto &row : grid)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
