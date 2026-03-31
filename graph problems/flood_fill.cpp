#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void dfsRecur(int i, int j, vector<vector<int>> &img, int orginalColour, int newColour, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || img[i][j] != orginalColour || img[i][j] == newColour)
    {
        return;
    }

    img[i][j] = newColour;
    dfsRecur(i + 1, j, img, orginalColour, newColour, m, n);
    dfsRecur(i, j + 1, img, orginalColour, newColour, m, n);
    dfsRecur(i - 1, j, img, orginalColour, newColour, m, n);
    dfsRecur(i, j - 1, img, orginalColour, newColour, m, n);
}
vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int newColor)
{
    int m = img.size();
    int n = img[0].size();
    int orginColour = img[sr][sc];
    dfsRecur(sr, sc, img, orginColour, newColor, m, n);
    return img;
}
int main()
{
    vector<vector<int>> img = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};

    int sr = 1, sc = 2;

    int newColor = 2;

    vector<vector<int>> result = floodFill(img, sr, sc, newColor);

    for (auto &row : result)
    {
        for (auto &pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
    return 0;
}
// 2 2 2 0
// 0 2 2 2
// 1 0 2 2