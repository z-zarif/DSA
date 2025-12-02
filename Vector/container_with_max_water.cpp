#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(vector<int> &height)
    {
        int n = height.size();
        int l = 0;
        int r = n-1;
        // area- w*h;
        //  w is r-l
        //  h is min or r and l
        //  we move the pointer, based on the minimum
        //  height = [1,8,6,2,5,4,8,3,7]
        int maxarea = 1;
        int area = 1;
        while (r > l)
        {
            int a = min(height[l], height[r]);
            area = (r - l) * a;
            if (a == height[l])
            {
                l++;
            }
            if (a == height[r])
            {
                r--;
            }
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};