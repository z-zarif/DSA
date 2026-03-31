#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int minProduct(vector<int> &arr, int k)
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
    int result = 1;
    while (!pq.empty())
    {
        result *= pq.top();
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> arr1 = {198, 76, 544, 123, 154, 675};
    cout << minProduct(arr1, 2) << endl; // Output: 9348

    vector<int> arr2 = {5, 4, 1, 2, 3};
    cout << minProduct(arr2, 3) << endl; // Output: 6

    return 0;
}