#include <bits/stdc++.h>
using namespace std;
// this is a brute force soltuion. It will give a TLE, because O(n) only works for 10^8.
class solution
{
public:
    int solve(double x, int n)
    {
        double ans = 1;
        int a = n;
        if (n < 0)
        {
            a = -n;
        }

        for (int i = 0; i < a; i++)
        {
            ans = ans * x;
        }
        if (n < 0)
        {
            ans = 1 / ans;
        }

        return ans;
    }
};
// Optimised Solution
// this process is known as binary exponentiation. This is very important to solve problems

class solution2
{
public:
    int solve(double x, int n)
    {
        long binum = n;
        if (n < 0)
        {
            binum = (-binum);
            x = 1.0 / x;
        }

        int ans = 1;
        while (binum > 0)
        {
            if ((binum % 2) == 1)
            {
                ans = ans * x;
            }
            x = x * x;
            binum /= 2;
        }

        return ans;
    }
};