#include <bits/stdc++.h>
using namespace std;
// only applicable for sorted array
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0;
        int j = (nums.size()) - 1;
        vector<int> ans;
        int ps = 0;
        while (i < j)
        {
            ps = nums[i] + nums[j];
            if (ps == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if (ps > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};