/*Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.*/

/*Solve:
if we have to find numbers and duplicates, we have to cancel out.
 two process of cancelling out
 >> if sign is different, we just add them. +4-4=0;
 >> if sign same, we just XOR them. >> n^n=0; >> n^0=n
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v1;
    int ans = 0;
    for (auto num : v1)
    {
        ans = ans ^ num;
    }

    cout << ans;
    return 0;
}
