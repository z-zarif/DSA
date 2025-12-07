#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int solve(vector<int> &arr)
    {
        int start = 1;
        int end = arr.size() - 2;//because for a mountain array, the first and last element can not be the peak
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            if (arr[mid-1] < arr[mid])// this shows my current mid is in increasing part of the triangle
            {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        return -1;
    }
};