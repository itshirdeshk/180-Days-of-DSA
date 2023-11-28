#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Wave Form.
void waveForm(int arr[][4], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < row; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = row - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

// Q2. Spiral Matrix.
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, right = col - 1, bottom = row - 1, left = 0;
    while (top <= bottom && left <= right)
    {
        // Print Top
        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
        }
        top++;

        // Print Right
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Print Bottom
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // Print Left
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

// Q3. Transpose of Matrix.
void transpose(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    // Creating a 2D Matrix
    vector<vector<int>> matrix;
    vector<vector<int>> matrix1(3, vector<int>(3, 2));

    cout << "Rows : " << matrix.size() << endl;
    cout << "Columns : " << matrix[0].size() << endl;
}