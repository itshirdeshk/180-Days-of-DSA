#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Search a 2D Matrix.
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int N = matrix.size(), M = matrix[0].size();
    int start = 0, end = N * M - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int row_index = mid / M;
        int col_index = mid % M;

        if (matrix[row_index][col_index] == target)
            return 1;
        else if (matrix[row_index][col_index] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

// Q2. Search in a row-column sorted Matrix.
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    // code here
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == x)
            return 1;
        else if (matrix[i][j] > x)
            j--;
        else
            i++;
    }

    return 0;
}

int main() {}