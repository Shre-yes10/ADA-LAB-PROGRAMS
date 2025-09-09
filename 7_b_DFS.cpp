#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, adj);
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter " << e << " edges (u v format , 0-indexed) : \n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int count = 0;

    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            dfs(node, visited, adj);
            count++;
        }
    }

    if (count == 1)
        cout << "The Graph is Connected\n";
    else
        cout << "The Graph is Disconnected\n";
 
    return 0;
}