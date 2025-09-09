#include <iostream>
using namespace std;

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX];

int find(int i)
{
    while (parent[i] > 0)
        i = parent[i];
    return i;
}

int main()
{
    int n, mincost = 0, ne = 1;

    cout << "Enter the number of vertices : ";
    cin >> n;

    cout << "Enter the cost matrix (use 999 for no edge/self loop) : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    while (ne < n)
    {
        int a = -1, b = -1, min = INF;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = find(a);
        int v = find(b);

        if (u != v)
        {
            parent[v] = u;
            cout << "Edge - " << ne++ << "(" << a << "," << b << "): " << min << endl;
            mincost = mincost + min;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    cout << "Minimum Cost = " << mincost << endl;

    return 0;
}