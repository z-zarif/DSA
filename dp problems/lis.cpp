#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i]>arr[j])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
            
        }
    }
    return *max_element(lis.begin(),lis.end());
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lis(arr) << endl;
    return 0;
}