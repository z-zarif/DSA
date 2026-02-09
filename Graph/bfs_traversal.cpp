// travel to immediate neighbours first
// mark as visited
// take a queue
// take an array
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
    void BFS()
    {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(0);
        vis[0] = true;
        while (!q.empty())
        {
            int u = q.front(); // source=u
            cout << u <<" ";
            q.pop();
            for (auto v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    fastIO();
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.BFS();

    return 0;
}
