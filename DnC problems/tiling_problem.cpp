#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<int>>tiling(int n, pair<int,int>missing_cell)
{
    
}
int main(){
    int n = 4;
    pair<int,int> missing_cell = {0,1};
    vector<vector<int>> grid = tiling(n, missing_cell);

    for (const auto &row : grid)
    {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}