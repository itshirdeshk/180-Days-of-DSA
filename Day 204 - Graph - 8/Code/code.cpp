#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Q1. Covid Spread.
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}
int helpaterp(vector<vector<int>> hospital)
{
    // code here
    r = hospital.size();
    c = hospital[0].size();

    // BFS
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (hospital[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    int timer = 0;
    while (!q.empty())
    {
        timer++;
        int curr_patient = q.size();
        while (curr_patient--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k]) && hospital[i + row[k]][j + col[k]] == 1)
                {
                    hospital[i + row[k]][j + col[k]] = 2;
                    q.push(make_pair(i + row[k], j + col[k]));
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (hospital[i][j] == 1)
            {
                return -1;
            }
        }

    return timer - 1;
}

// Q2. Find the number of islands.
int c, r;
int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}
// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    // Check the char 1 in out grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                q.push(make_pair(i, j));
                grid[i][j] = '0';

                while (!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;

                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        if (valid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == '1')
                        {
                            grid[new_i + row[k]][new_j + col[k]] = '0';
                            q.push(make_pair(new_i + row[k], new_j + col[k]));
                        }
                    }
                }
            }
        }
    }
    return count;
}

// Q3. Replace O's with X's.
int r, c;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    r = n;
    c = m;

    queue<pair<int, int>> q;

    // First row
    for (int j = 0; j < c; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push(make_pair(0, j));
            mat[0][j] = 'T';
        }
    }

    // First col
    for (int j = 1; j < r; j++)
    {
        if (mat[j][0] == 'O')
        {
            q.push(make_pair(j, 0));
            mat[j][0] = 'T';
        }
    }

    for (int j = 1; j < c; j++)
    {
        if (mat[r - 1][j] == 'O')
        {
            q.push(make_pair(r - 1, j));
            mat[r - 1][j] = 'T';
        }
    }

    for (int j = 1; j < r - 1; j++)
    {
        if (mat[j][c - 1] == 'O')
        {
            q.push(make_pair(j, c - 1));
            mat[j][c - 1] = 'T';
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
            {
                q.push(make_pair(i + row[k], j + col[k]));
                mat[i + row[k]][j + col[k]] = 'T';
            }
        }
    }

    // Replace all with O with X
    // Replace all with T with O
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == 'T')
                mat[i][j] = 'O';
        }
    }

    return mat;
}

int main() {}