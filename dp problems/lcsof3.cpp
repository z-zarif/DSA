#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int lcsOf3(string &s1, string &s2, string &s3)
{
    int x = s1.length();
    int y = s2.length();
    int z = s3.length();
    vector<vector<vector<int>>> dp((x + 1), vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            for (int k = 1; k <= z; k++)
            {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
                {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[x][y][z];
}

int main()
{
    string s1 = "AGGT12";
    string s2 = "12TXAYB";
    string s3 = "12XBA";
    int res = lcsOf3(s1, s2, s3);
    cout << res << endl;

    return 0;
}