#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Q1. Detect cycle in a directed graph.
// By using DFS:
bool detectCycle(int node, vector<int> adj[], vector<bool> &path, vector<bool> &visited)
{
    visited[node] = 1;
    path[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (path[adj[node][i]])
            return 1;

        if (visited[adj[node][i]])
            continue;

        if (detectCycle(adj[node][i], adj, path, visited))
            return 1;
    }

    path[node] = 0;
    return 0;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> path(V, 0);
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && detectCycle(i, adj, path, visited))
            return 1;
    }

    return 0;
}

// By using BFS:
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> inDeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (!inDeg[i])
            q.push(i);
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int i = 0; i < adj[node].size(); i++)
        {
            inDeg[adj[node][i]]--;
            if (!inDeg[adj[node][i]])
                q.push(adj[node][i]);
        }
    }
    return count != V;
}

int main() {}