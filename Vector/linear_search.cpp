#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //random vector generator of random size
    srand(time(0)); 
    int size = rand() % 16 + 5;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        v[i] = rand() % 100 + 1;
    }
    int tofind = 61;
    bool found = false;
    for (auto val : v)
    {
        if (val == tofind)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "found" << endl;
    }

    return 0;
}