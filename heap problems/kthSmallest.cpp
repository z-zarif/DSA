#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
   return pq.top();
}
int main()
// Driver Code Starts
{
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << kthSmallest(arr, k);
}
// ans 5;