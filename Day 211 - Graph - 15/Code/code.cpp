#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q1. Floyd Warshall.
// Method 1:
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}

// Method 2:
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                    continue;

                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }

                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main() {}