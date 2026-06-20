#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    map<T, vector<T>> adj;

public:
    void addEdge(T u, T v, bool directed = false)
    {
        adj[u].push_back(v);
        if (!directed)
        {
            adj[v].push_back(u);
        }
    }
    void addVertex(T vertex)
    {
        adj[vertex];
    }
    void removeEdge(T u, T v, bool directed)
    {
        auto &p = adj[u];
        p.erase(remove(p.begin(), p.end(), v), p.end());
        if (!directed)
        {
            auto &t = adj[v];
            t.erase(remove(t.begin(), t.end(), t), t.end());
        }
    }
    void removeVertex(T vertex)
    {
        for (auto it = adj.begin(); it != adj.end(); ++it)
        {
            auto &neighbours = it.second;
            neighbours.erase(remove(neighbours.begin(), neighbours.end(), vertex), neighbours.end());
        }
        adj.erase(vertex);
    }
    void Print()
    {
        for (auto it = adj.begin(); it != adj.end(); ++it)
        {
            cout << it->first << "- >";
            for (auto neighbour : it->second)
            {
                cout << neighbour << " ";
            }
            cout << "\n";
        }
    }
};


