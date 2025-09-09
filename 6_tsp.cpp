#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

#define MAX 10

int main()
{
    int n, cost[MAX][MAX];
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int cities[MAX];
    for (int i = 0; i < n; i++)
        cities[i] = i;
    int minCost = INT_MAX;
    do
    {
        int c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            c += cost[cities[i]][cities[i + 1]];
        }
        c += cost[cities[n - 1]][cities[0]];
        minCost = min(minCost, c);
    } while (next_permutation(cities + 1, cities + n));

    bool visited[MAX] = {false};
    int total = 0, current = 0;
    visited[0] = true;
    for (int k = 1; k < n; k++)
    {
        int next = -1, best = INT_MAX;
        for (int j = 0; j < n; j++)
            if (!visited[j] && cost[current][j] < best)
            {
                best = cost[current][j];
                next = j;
            }
        visited[next] = true;
        total += best;
        current = next;
    }
    total += cost[current][0];

    cout << "\nOptimal TSP Cost = " << minCost;
    cout << "\nApproximation (Nearest Neighbor) Cost = " << total;
    float error = ((float)(total - minCost) / minCost) * 100;
    cout << "\nError in approximation = " << error << "%\n";

    return 0;
}
