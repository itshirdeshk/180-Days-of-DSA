#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count, int N)
{
    visited[node] = 1;
    count++;

    if (count == N)
        return 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]] && DFS(adj[node][j], adj, visited, count, N))
            return 1;
    }

    visited[node] = 0;
    count--;
    return 0;
}

bool check(int N, int M, vector<vector<int>> Edges)
{
    // code here
    vector<vector<int>> adj(N); 
    for (int i = 0; i < M; i++)
    {
        adj[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
        adj[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
    }

    vector<bool> visited(N, 0);
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (DFS(i, adj, visited, count, N))
            return 1;
    }

    return 0;
}

int main() {}