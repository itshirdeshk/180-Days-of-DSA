#include <iostream>
#include <vector>
using namespace std;

// Q1. N-Queens.
void find(int row, int n, vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &leftDig, vector<bool> &rightDig)
{
    // Base Condition
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    // Put queen at any n position
    for (int i = 0; i < n; i++)
    {
        if (column[i] == 0 && leftDig[n - 1 + (i - row)] == 0 && rightDig[row + i] == 0)
        {
            column[i] = 1;
            board[row][i] = 'Q';
            leftDig[n - 1 + (i - row)] = 1;
            rightDig[row + i] = 1;
            find(row + 1, n, ans, board, column, leftDig, rightDig);
            column[i] = 0;
            board[row][i] = '.';
            leftDig[n - 1 + (i - row)] = 0;
            rightDig[row + i] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i].push_back('.');

    vector<bool> leftDig(2 * n - 1, 0);
    vector<bool> rightDig(2 * n - 1, 0);

    vector<bool> column(n, 0);

    find(0, n, ans, board, column, leftDig, rightDig);

    return ans;
}

// Q2. M-Coloring Problem.
bool find(int node, bool graph[101][101], int n, int m, vector<int> &color)
{
    if (node == n)
        return 1;
    for (int i = 0; i < m; i++)
    {
        bool isPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                isPossible = 0;
                break;
            }
        }

        if (isPossible)
        {
            color[node] = i;
            if (find(node + 1, graph, n, m, color))
                return 1;
            color[node] = -1;
        }
    }
    return 0;
}
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> color(n, -1);
    return find(0, graph, n, m, color);
}

// Q3. Sudoku Solver.
bool check(int num, vector<vector<char>> &board, int i, int j)
{
    char c = '0' + num;
    // check at same row
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == c)
            return 0;
    }
    // check at same col
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == c)
            return 0;
    }
    // check at same block
    int row = i / 3 * 3, col = j / 3 * 3;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (board[row + a][col + b] == c)
                return 0;
        }
    }

    return 1;
}

bool find(int i, int j, vector<vector<char>> &board)
{
    if (i == 9)
        return 1;
    if (j == 9)
        return find(i + 1, 0, board);

    if (board[i][j] != '.')
        return find(i, j + 1, board);

    for (int num = 1; num <= 9; num++)
    {
        if (check(num, board, i, j))
        {
            board[i][j] = '0' + num;
            if (find(i, j + 1, board))
                return 1;
            board[i][j] = '.';
        }
    }
    return 0;
}

void solveSudoku(vector<vector<char>> &board)
{
    find(0, 0, board);
}


int main() {}