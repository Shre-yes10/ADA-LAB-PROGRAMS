#include <iostream>
using namespace std;

int n, d, a[10], x[10], cnt = 0, flag = 0;

void subset(int i, int sum)
{
    if (sum == d)
    {
        flag = 1;
        cout << "{";
        for (int k = 0; k < cnt; k++)
            cout << " " << x[k] << " ";
        cout << "}\n";
        return;
    }
    if (i >= n || sum > d)
        return;

    x[cnt++] = a[i]; 
    subset(i + 1, sum + a[i]);
    cnt--; 
    subset(i + 1, sum);
}

int main()
{
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the values : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the Sum : ";
    cin >> d;

    cout << "Solution : \n";
    subset(0, 0);
    if (flag == 0)
        cout << "There is no solution\n";
    return 0;
}
