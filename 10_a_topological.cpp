#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges : ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    cout << "Enter the edges (from to) : \n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    cout << "Topological Order : ";
    while (!q.empty())
    {
        int u = q.front();
        cout << " " << u;
        q.pop();

        for (int v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return 0;
}