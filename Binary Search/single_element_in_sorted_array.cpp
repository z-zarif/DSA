#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(vector<int> &nums)
    {
        int start = 0;
        int n = nums.size();
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid == 0 && nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid == (n - 1) && nums[mid] != nums[mid - 1])
                return nums[mid];
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid - 1])
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};