#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int sumBetween(vector<int> &arr, int k1, int k2)
{
    int n = arr.size();
    priority_queue<int> pq;
    priority_queue<int> pq2;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        pq2.push(arr[i]);
        if (pq.size() > k1)
        {
            pq.pop();
        }
        if (pq2.size() > k2)
        {
            pq2.pop();
        }
    }
    int lowerBound = pq.top();
    int upperBound = pq2.top();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > lowerBound && arr[i] < upperBound)
        {
            sum += arr[i];
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;
    cout << sumBetween(arr, k1, k2);
    return 0;
}