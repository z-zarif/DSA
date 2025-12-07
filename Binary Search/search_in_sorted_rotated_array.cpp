#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(vector<int> &nums, int target)
    {
        // for a rotated sorted array,
        //  either right half will be sorted
        //  or left half will be sorted
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target <= nums[mid])
                {
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            else
            {
                if (nums[mid] <= target <= nums[end])
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