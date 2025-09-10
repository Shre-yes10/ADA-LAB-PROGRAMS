#include <iostream>
using namespace std;

#define MAX 10
#define INF 999

int cost[MAX][MAX];

int main()
{                                                                              // TC - O(E log V)
    int n, mincost = 0, ne = 1;                                                // SC - O(V+E)

    cout << "Enter the number of vertices : ";
    cin >> n;

    cout << "Enter the cost matrix (use 999 for no edge / self loop) : \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int visited[MAX] = {0};
    visited[1] = 1;

    while (ne < n)
    {
        int a = -1, b = -1, min = INF;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;
        cout << "Edge - " << ne++ << " (" << a << "," << b << "): " << min << endl;
        mincost = mincost + min;
    }
    cout << "Minimum Cost : " << mincost << endl;
}