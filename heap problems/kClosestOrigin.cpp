#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<int>> kClosest(vector<vector<int>>&points,int k)
{
    priority_queue<pair<int,vector<int>>>pq;
     
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    
    vector<vector<int>> res = kClosest(points, k);
    
    for (vector<int> point : res) {
        cout << point[0] << ", " << point[1];
        cout<<endl;
    }

    return 0;
}
