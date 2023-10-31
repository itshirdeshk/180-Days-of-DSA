#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Given a Matrix of size n*m (n=rows and m= cols). Reverse each column of the matrix.
void reverse(vector<vector<int>> matrix, int row, int col)
{
    int index = row - 1;
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            swap(matrix[i][j], matrix[index][j]);
        }
        index--;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
}

// Q2. Spiral Matrix - 2.

// Q3. Print Diagonally.
vector<int> downwardDiagonal(int N, vector<vector<int>> A)
{
    // Your code goes here
    vector<int> ans;
    int row = 0, col = 0;

    for (int i = 0; i < N; i++)
    {
        row = 0;
        col = i;
        while (row <= i && col >= 0)
        {
            ans.push_back(A[row][col]);
            row++;
            col--;
        }
    }

    for (int i = 1; i < N; i++)
    {
        row = i;
        col = N - 1;
        while (row <= N - 1 && col >= i)
        {
            ans.push_back(A[row][col]);
            row++;
            col--;
        }
    }

    return ans;
}

// Q4. Print matrix in diagonal pattern.

// Q5. Print Matrix in snake pattern.

int main() {}