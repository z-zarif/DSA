#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int tar, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid])
        {
            return bs(arr, tar, mid + 1, end);
        }
        else if (tar < arr[mid])
        {
            return bs(arr, tar, st, mid - 1);
        }
        else
            return mid;
    }
    else
        return -1;
}

int main()
{
   // int start = INTMAX_MAX;
   // int end = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    // basic binary search

    // binary search using recursion

    vector<int> v={2,3,5,7,9,11,34,67,78,89,99};
    int target=11;
    cout<<bs(v,target,0,11)<<endl;

    return 0;
}