#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int longestPalinSubseq(string &s)
{
    int n=s.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = i; j <n; j++)
        {
            if(i==j)
            {
                dp[i][j]=1;
                continue;
            }
            if (s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
    }
    return dp[0][n-1];
    

}

int main() {
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}