#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Count zeros in a sorted matrix.
int countZeros(vector<vector<int>> A)
{
    // code here
    int count = 0;
    for (int i = 0; i < A.size() * A.size(); i++)
    {
        int row = i / A.size();
        int col = i % A.size();

        if (A[row][col] == 0)
            count++;
    }

    return count;
}

// Q2. Row with max 1s.
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int index = -1;
    int count = 0;
    int i = 0, j = m - 1;
    while (i >= 0 && j >= 0 && i < n && j < m)
    {
        if (arr[i][j] == 1)
        {
            int newCount = m - j;
            if (newCount > count)
            {
                count = newCount;
                index = i;
            }
            j--;
        }
        else
        {
            i++;
        }
    }
    return index;
}

// Q3. Binary Search in a 2D array which is sorted in decreasing order. N is the number of rows and M is the number of columns.
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
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main() {}