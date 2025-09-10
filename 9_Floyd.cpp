#include <iostream>
#include <vector>
using namespace std;

void floyd(vector<vector<int>> &mat)
{                                                                       // TC - O(V^3)
    int n = mat.size();                                                 // SC - O(V^2)

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
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n)); /////////////

    cout << "Enter the adjacency matrix (use -1 for no edge): \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    floyd(graph);

    cout << "\nShortest Distance Matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
