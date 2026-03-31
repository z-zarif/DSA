#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void findFrequencies(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int val = arr[i];
        int start = i;
        int end = n - 1;
        int endIdx = i;

        while (end >= start)
        {
            int mid = start + (end - start) / 2;
            if (val == arr[mid])
            {
                endIdx = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        int cnt = endIdx - i + 1;
        cout << val << " " << cnt << endl;
        i = endIdx + 1;
    }
}
int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};                    
    findFrequencies(arr);
    return 0;
}