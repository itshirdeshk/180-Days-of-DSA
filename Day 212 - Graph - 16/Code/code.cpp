#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Shortest Source to Destination Path.
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
    // code here

    if (X == 0 && Y == 0)
        return 0;

    if (!A[0][0])
        return -1;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    visited[0][0] = 1;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second.first;
        int step = q.front().second.second;

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int new_i = i + row[k];
            int new_j = j + col[k];

            if (valid(new_i, new_j, N, M) && A[new_i][new_j] && !visited[new_i][new_j])
            {

                if (new_i == X && new_j == Y)
                    return step + 1;

                visited[new_i][new_j] = 1;
                q.push({new_i, {new_j, step + 1}});
            }
        }
    }
    return -1;
}

// More Optimized Solution:
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
{
    // code here

    if (X == 0 && Y == 0)
        return 0;

    if (!A[0][0])
        return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    // vector<vector<bool>> visited(N, vector<bool> (M, 0));
    // visited[0][0] = 0;
    A[0][0] = 0;
    int step = 0;

    while (!q.empty())
    {

        int count = q.size();
        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                {

                    if (new_i == X && new_j == Y)
                        return step + 1;

                    A[new_i][new_j] = 0;
                    q.push({new_i, new_j});
                }
            }
        }
        step++;
    }
    return -1;
}

// Q2. Knight Walk.
int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here

    if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
        return 0;

    queue<pair<int, int>> q;
    vector<vector<bool>> chess(N, vector<bool>(N, 0));

    q.push({KnightPos[0] - 1, KnightPos[1] - 1});
    chess[KnightPos[0] - 1][KnightPos[1] - 1] = 1;

    int step = 0;

    while (!q.empty())
    {
        int count = q.size();

        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, N) && !chess[new_i][new_j])
                {
                    if (new_i == TargetPos[0] - 1 && new_j == TargetPos[1] - 1)
                        return step + 1;

                    chess[new_i][new_j] = 1;
                    q.push({new_i, new_j});
                }
            }
        }
        step++;
    }
    return -1;
}

// Q3. Find whether path exist.
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

// Function to find whether a path exists from the source to destination.
bool is_Possible(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                grid[i][j] = 0;
                break;
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int new_i = i + row[k];
            int new_j = j + col[k];

            if (valid(new_i, new_j, n) && grid[new_i][new_j])
            {
                if (grid[new_i][new_j] == 2)
                    return 1;

                q.push({new_i, new_j});
                grid[new_i][new_j] = 0;
            }
        }
    }

    return 0;
}

int main() {}