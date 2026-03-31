#include <iostream>
#include <vector>
#include <string>
using namespace std;

int distinctSubseq(string &str) {
    int n = str.size();
    int mod = 1000000007;

    // to store the results up to
    // each index i, from 0 to n
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    // to store the last occurrence 
    // of each character in the string
    vector<int> last(26, -1);

    for(int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % mod;

        // if the character is seen before
        // subtract the count of subsequences
        if(last[str[i - 1] - 'a'] != -1) {
            dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + mod) % mod;
        }

        // update the last occurrence of the character
        last[str[i - 1] - 'a'] = i - 1;
    }
    return dp[n];
}

int main() {
    string str = "gfg";
    cout << distinctSubseq(str);
    return 0;
}
