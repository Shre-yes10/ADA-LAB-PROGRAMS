#include <iostream>
#include <vector>
using namespace std;

void floyd(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != -1 && mat[k][j] != -1) 
                {
                    if (mat[i][j] == -1) 
                        mat[i][j] = mat[i][k] + mat[k][j];
                    else
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
}

int main()
{
    int V;
    cout << "Enter the number of vertices : ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (use -1 for no edge): \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }

    floyd(graph);

    cout << "\nShortest Distance Matrix : \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == -1)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
