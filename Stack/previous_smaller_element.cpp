#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> prevSmaller(vector<int> &arr)
{
    vector<int> ans;
    stack<int> s1;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s1.empty() && s1.top() >= arr[i])
        {
            s1.pop();
        }
        if (s1.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s1.top());
        }
        s1.push(arr[i]);
        }
    return ans;
}
int main()
{
    fastIO();

    vector<int> arr = {1, 5, 0, 3, 4, 5};
    vector<int> ans = prevSmaller(arr);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
// Expected Output: [-1 1 -1 0 3 4 ]