#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> getMinMax(vector<int> &arr, int low, int high)
{
    vector<int> result(2);
    if ((high - low) <= 2)
    {
        if (arr[low] < arr[high])
        {
            result[0] = arr[low];
            result[1] = arr[high];
        }
        else
        {
            result[1] = arr[low];
            result[0] = arr[high];
        }
        return result;
    }

    int mid = (low + high) / 2;
    vector<int> leftMinMax = getMinMax(arr, low, mid);
    vector<int> rightMinMax = getMinMax(arr, mid+1, high);
    result[0] = min(leftMinMax[0], rightMinMax[0]);
    result[1] = max(leftMinMax[1], rightMinMax[1]);
    return result;
}
vector<int> findMinMax(vector<int> &arr)
{
    return getMinMax(arr, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {3, 5, 4, 1, 9};
    vector<int> result = findMinMax(arr);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}