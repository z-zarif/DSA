#include <bits/stdc++.h>
using namespace std;

// what is stock span?
//  max number of !consecutive day! from today, where price <=today's price;
//! include current day's price
// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastIO();

    vector<int> arr = {10, 4, 5, 90, 120, 80};
    stack<int> s1;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        while (s1.size() > 0 && arr[s1.top()] <= arr[i])
        {
            s1.pop();
        }
        if (!s1.size())
            ans.push_back(i + 1);
        else
            ans.push_back(i - s1.top());
        s1.push(i);
    }
    for (auto i : ans)
        cout << i << " ";

    return 0;
}
