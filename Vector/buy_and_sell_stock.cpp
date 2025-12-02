#include <bits/stdc++.h>
using namespace std;
// brute force solution, runs into runtime error
class solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int maxprofit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int currnum = nums[i];
            for (int j = 0; j < n; j++)
            {
                int diff = nums[j] - currnum;
                maxprofit = max(diff, maxprofit);
            }
        }

        return maxprofit;
    }
};
// better solution, imagine everyday is a selling day

class solution2
{
public:
    int solve(vector<int> &price)
    {
        int n = price.size();
        int bestbuy = price[0];
        int maxprofit = 0;
        for (auto i = 1; i < n; i++)
        {
            if (price[i] > bestbuy)
            {
                maxprofit = max(maxprofit, (price[i] - bestbuy));
            }
            bestbuy = min(bestbuy, price[i]);
        }

        return maxprofit;
    }
};
