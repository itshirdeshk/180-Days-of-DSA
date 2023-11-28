#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Rotate Image.
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    };

    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }
}

// Q2.  Matrix Rotation by 180 degree.
void rotate(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();

    // Column wise reverse
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++, end--;
        }
    }

    // Row wise reverse
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }
}

// Q3. Rotate by 90 degree
void rotateby90(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    };

    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++, end--;
        }
    }
}

// Q4. 

int main() {}