#include <bits/stdc++.h>
using namespace std;
// brute force solution
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        for (auto x : nums)
        {
            int freq = 0;
            for (auto y : nums)
            {
                if (x == y)
                    freq++;
            }
            if (freq > n / 2)
            {
                return x;
            }
        }
        return -1;
    }
};
// optimised brute force
class optimisedsolution
{
public:
    int majelement(vector<int> &nums)
    {
        int n = nums.size();
        // sort
        sort(nums.begin(), nums.end());
        // frequency count
        int freq = 1;
        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                freq++;
            }
            else
            {
                freq = 1;
                ans = nums[i];
            }

            if (freq > n / 2)
            {
                return ans;
            }
        }
        return ans;
    }
};

// THE BEST WAY: MOORES VOTING ALGORITHM
/*if matches freq++, if doesn't match freq --.
Because, the intuition is regardless of the sorting, majority element  will always win*/

class solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int freq = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (freq == 0)
            {
                ans = nums[i];
            }
            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}