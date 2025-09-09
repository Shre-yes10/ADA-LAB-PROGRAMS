#include <iostream>
using namespace std;

void print(int board[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                cout << " Q ";
            else
                cout << " - ";
        }
        cout << "\n";
    }
    cout << "-----------------------------\n";
}

bool issafe(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void nqueen(int board[], int row, int n)
{
    if (row == n)
    {
        print(board, n);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (issafe(board, row, col))
        {
            board[row] = col;
            nqueen(board, row + 1, n);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens : ";
    cin >> n;
    int board[20];
    nqueen(board, 0, n);
    return 0;
}