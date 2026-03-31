#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool dfsRec(int u, vector<vector<int>> &adj, vector<bool> visited, vector<bool> recPath)
{
    visited[u] = true;
    recPath[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            if (dfsRec(v, adj, visited, recPath))
            {
                return true;
            }
        }
        else if (recPath[v])
        {
            return true;
        }
    }
    recPath[u] = false;
    return false;
}
bool isCyclic(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> recPath(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfsRec(i, adj, visited, recPath))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> adj = {{1}, {2}, {0, 3}};

    cout << (isCyclic(adj) ? "true" : "false") << endl;
    return 0;
}
