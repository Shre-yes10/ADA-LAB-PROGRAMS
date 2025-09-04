#include <iostream>
#include <vector>
using namespace std;

void warshall(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
        mat[i][i] = 1;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] && mat[k][j])
                    mat[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0=no edge , 1=edge) : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    warshall(graph);

    cout << "Transitive Closure : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << graph[i][j];
        }
        cout << endl;
    }
    return 0;
}