#include <bits/stdc++.h>
using namespace std;
// this is a hard, but very very important problem
bool isvalid(vector<int> &arr, int n, int m)
{
    int stu = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            return false;
        }
        if (pages + arr[i] < m)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
            
        }
        
    }
    if (stu <= n)
    {
        return true;
    }
    else
        return false;
}
class solution
{
public:
    int solve(vector<int> &arr, int n)
    {
        
        int start = 0;
        int sum = 0;
        int ans=-1;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        int end = sum;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isvalid(arr, n, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }
};