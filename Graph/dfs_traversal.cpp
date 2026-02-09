#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
class Graph
{
private:
    int V;
    list<int> *l;
    // int *arr;
public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    };
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // u is the source node;
    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }
    void DFS()
    {
        int src = 0;
        vector<bool> vis(V, false);
        dfsHelper(src, vis);
    }
};