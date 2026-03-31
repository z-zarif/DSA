#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longCommSubstr(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a table to store lengths of longest
    // common suffixes of substrings.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build dp[m+1][n+1] in bottom-up fashion.    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main() {
    
    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";
    cout << longCommSubstr(s1, s2) << endl;
    return 0;
}