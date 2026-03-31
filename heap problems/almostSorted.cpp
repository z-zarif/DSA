#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> nearlySorted(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            res[count++] = pq.top();
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        res[count++] = pq.top();
        pq.pop();
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    vector<int> res = nearlySorted(arr, k);
    for (int x : res)
        cout << x << ' ';
    return 0;
}
// 1 2 3 4