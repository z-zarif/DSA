#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> nextGreaterElement(vector<int> &arr)
{
    vector<int> ans;
    stack<int> s1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {

        while (!s1.empty() && s1.top() <= arr[i])
        {
            s1.pop();
        }

        if (s1.empty())
            ans.push_back(-1);
        else
            ans.push_back(s1.top());
        s1.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    fastIO();

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextGreaterElement(arr);

    for (int x : res)
    {
        cout << x << " ";
    }
    // Expected Output [8 -1 1 3 -1]

    return 0;
}