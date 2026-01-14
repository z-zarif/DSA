// follows divide and conquer method
//TC=total calls*work done in each call
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> v;
    int left = start;
    int right = mid + 1;
    int k = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            v.push_back(arr[left++]);
        }
        else
        {
            v.push_back(arr[right++]);
        }
    }
    while (left <= mid)
    {
        v.push_back(arr[left++]);
    }
    while (right <= end)
    {
        v.push_back(arr[right++]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        arr[start + i] = v[i];
    }
}
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> a = {4, 6, 7, 3, 73, 44, 347, 445, 343342, 43534, 34, 2, 2, 2, 2464, 37, 357, 3, 3};
    mergeSort(a, 0, a.size() - 1);
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}
