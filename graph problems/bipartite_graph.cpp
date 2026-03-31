#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    return adj;
}
bool isBipartite(int V, vector<vector<int>> &edges)
{
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> colour(V, -1);
    vector<vector<int>> adj = constructAdj(V, edges);
    for (int i = 0; i < V; i++)
    {
        if (colour[i] == -1)
        {
            colour[i] = 0;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (!visited[v] && colour[v] == -1)
                    {
                        visited[v] = true;
                        colour[v] = 1 - colour[u];
                        q.push(v);
                    }
                    else if (colour[v] == colour[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if (isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";

    return 0;
}
