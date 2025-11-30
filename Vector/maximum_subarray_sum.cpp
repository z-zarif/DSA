#include <bits/stdc++.h>
using namespace std;
// KADANE'S ALGORITHM
// never add larger negative with smaller positve
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int size = rand() % 16 + 5;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % 100 + 1;
    }
    int currsum = 0;
    int maxsum = INT_MIN;
    for (auto i : v)
    {
        currsum += i;
        maxsum = max(currsum, maxsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }

    return 0;
}