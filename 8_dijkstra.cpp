#include <iostream>
#include <vector>
using namespace std;

#define INF 999

int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n)); ///////////
    cout << "Enter the adjacency matrix (use 999 for no edge) : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int src;
    cout << "Enter the source vertex : ";
    cin >> src;

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int k = 0; k < n - 1; k++)
    {
        int u = -1, min = INF;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && g[u][v] != INF && dist[u] + g[u][v] < dist[v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
    cout << "Shortest Distances from " << src << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "To " << i << "=" << dist[i] << endl;
    }
    return 0;
}