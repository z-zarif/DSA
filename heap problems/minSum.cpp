#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int minSum(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    string num1, num2;
    while (!pq.empty())
    {
        num1 += to_string(pq.top());
        pq.pop();
        if (!pq.empty())
        {
            num2 += to_string(pq.top());
            pq.pop();
        }
    }
    return stoi(num1)+stoi(num2);
}
int main()
{
    fastIO();
    vector<int> arr = {5, 3, 0, 7, 4};
    cout << minSum(arr) << endl;

    return 0;
}