// Network of nodes
//  nodes and edges
#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
// adjacency list
// store neighbours for all vertices
class Graph
{
private:
    int V;
    list<int> *l; // int *arr;
    // dynamic array of doubly linked list
public:
    Graph(int v)
    {
        this->V = v;
        // arr=new int[v];
        l = new list<int>[V];
    };
    // suppose an edge is between 1,3. so now, we have to add 3 in the list of 1 and vice versa.
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << ": ";
            for (auto neighbour : l[i])

            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
    
};

int main()
{
    fastIO();
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.printAdjList();

    return 0;
}