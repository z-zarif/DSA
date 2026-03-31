#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
//backedge is the condition for cycle in undirected graph
//vissited but not parent
bool isCycledUndirDFS(int src,int par,vector<bool>&vis,vector<vector<int>>&adj)
{
    vis[src]=true;
    for(int v:adj[src])
    {
        if (!vis[v])
        {
            if(isCycledUndirDFS(v,src,vis,adj))
            {
                return true;
                
            }
        } else if (v!=par)
        {
            return true;
        }
        
    }
    return false;
}
bool isCycle(vector<vector<int>>&adj)
{
    int V=adj.size();
    vector<bool>vis(V,false);
    for (int i = 0; i <  V; i++)
    {
        if (!vis[i])
        {
            if (isCycledUndirDFS(i,-1,vis,adj))
            {
                return true;
            }
            
        }
        
    }
    return false;
    
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    isCycle(adj) ? cout << "true" : cout << "false";

    return 0;

}
