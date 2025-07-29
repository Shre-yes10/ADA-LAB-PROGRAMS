#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void queen(vector<vector<bool>> &board, int row);
bool isSafe(vector<vector<bool>> &board, int row, int col);
void display(vector<vector<bool>> &board);

void queen(vector<vector<bool>> &board, int row)
{
    if (row == board.size())
    {
        display(board);
        cout << "----------------------------------------\n";
        return;
    }
    for (int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = true;
            queen(board, row + 1);
            board[row][col] = false;
        }
    }
}

bool isSafe(vector<vector<bool>> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    
    int maxLeft = min(row, col);
    for (int i = 1; i <= maxLeft; i++)
    {
        if (board[row - i][col - i])
            return false;
    }

    int maxRight = min(row, (int)board.size() - col - 1);
    for (int i = 1; i <= maxRight; i++)
    {
        if (board[row - i][col + i])
            return false;
    }
    return true;
}

void display(vector<vector<bool>> &board)
{
    for (auto row : board)
    {
        for (auto element : row)
        {
            element ? cout << "Q " : cout << "- ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter the Board Size (NxN) : ";
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    queen(board, 0);
    return 0;
}