#include <iostream>
using namespace std;

#define MAX 10
#define INF 999

int cost[MAX][MAX];

int main()
{
    int n, mincost = 0, ne = 1;

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

        cout << "Edge - " << ne++ << "(" << a << "," << b << "): " << min << endl;
        visited[b] = 1;
        mincost = mincost + min;
    }
    cout << "Minimum Cost : " << mincost << endl;
}