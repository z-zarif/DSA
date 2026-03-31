#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int bottomup(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}
int lcs(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    return bottomup(s1, s2, m, n, dp);
}
int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2) << endl;
    return 0;
}