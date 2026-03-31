#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int floorSqrt(int n)
{
    int low = 1;
    int high = n;
    int result;
    while (high > low)
    {
        int mid = (low + high) / 2;
        if (mid * mid <= n)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int main()
{
    int n = 16;
    cout << floorSqrt(n);
    return 0;
}