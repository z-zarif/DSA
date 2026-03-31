#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    int inversionCount = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            inversionCount += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        /* code */ temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + st] = temp[i];
    }

    return inversionCount;
}
int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);
        int invCount = merge(arr, st, mid, end);
        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}
int main()
{
    fastIO();
    vector<int> arr = {4, 3, 2, 1};

    cout << mergeSort(arr, 0, arr.size() - 1);
    return 0;
}