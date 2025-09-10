#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>                                                    // TC - O(V+E)
using namespace std;                                                // SC - O(V)

int main()
{
    int n, e;
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> e;

    vector<vector<int>> adj(n);
    cout << "Enter the edges (from to) : \n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node : ";
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Reachable nodes from " << start << " using BFS : \n";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return 0;
}