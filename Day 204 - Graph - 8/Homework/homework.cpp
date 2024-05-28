#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Rotten Oranges.
int r, c;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}
// Function to find minimum time required to rot all oranges.
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    if (q.empty())
        return 0;

    int timer = 0;

    while (!q.empty())
    {
        timer++;
        int curr_oranges = q.size();

        while (curr_oranges--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k]) && grid[i + row[k]][j + col[k]] == 1)
                {
                    q.push(make_pair(i + row[k], j + col[k]));
                    grid[i + row[k]][j + col[k]] = 2;
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return timer - 1;
}

// Q2. X Total Shapes.
int r, c;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}
// Function to find the number of 'X' total shapes.
int xShape(vector<vector<char>> &grid)
{
    // Code here
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'X')
            {
                count++;
                q.push(make_pair(i, j));
                grid[i][j] = 'O';

                while (!q.empty())
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        if (valid(i + row[k], j + col[k]) && grid[i + row[k]][j + col[k]] == 'X')
                        {
                            q.push(make_pair(i + row[k], j + col[k]));
                            grid[i + row[k]][j + col[k]] = 'O';
                        }
                    }
                }
            }
        }
    }
    return count;
}

// Q3. Number of Provinces.
void dfs(int node, vector<vector<int>> &adj, map<int, bool> &visited)
{

    visited[node] = 1;

    for (int nbr = 0; nbr < adj[node].size(); nbr++)
    {
        if (adj[node][nbr] == 1 && !visited[nbr])
        {
            dfs(nbr, adj, visited);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    map<int, bool> visited;
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, adj, visited);
        }
    }
    return count;
}

int main() {}