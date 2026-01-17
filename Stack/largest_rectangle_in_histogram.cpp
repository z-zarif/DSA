#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> rightSmallerElement(vector<int> &arr)
{
    stack<int> s;
    vector<int> rightans;
    for (int i = arr.size() - 1; i >= 0; i--)//!
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        rightans.push_back(s.empty() ? arr.size() : s.top());//!
        s.push(i);
    }
    reverse(rightans.begin(), rightans.end());
    return rightans;
}
vector<int> leftSmallerElement(vector<int> &arr)
{
    stack<int> s1;
    vector<int> leftans;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s1.empty() && arr[s1.top()] >= arr[i])
        {
            s1.pop();
        }
        leftans.push_back(s1.empty() ? -1 : s1.top());
        s1.push(i);
    }
    return leftans;
}

int getMaxArea(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;
    vector<int> leftans = leftSmallerElement(arr);
    vector<int> rightans = rightSmallerElement(arr);
    for (int i = 0; i < n; i++)
    {
        int left = leftans[i];
        int right = rightans[i];
        int area = arr[i] * (right - left- 1);
         maxArea = max(area, maxArea);
    }
    return maxArea;
}
int main()
{
    fastIO();

    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;

    return 0;
}
//Expected Output: 100