#include <iostream>
#include <vector>
using namespace std;

// Q1. Euler circuit and Path.
void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}

int isEulerCircuit(int V, vector<int> adj[])
{
    // Code here
    // Euler Circuit: 2
    // Calculate the degree of each node
    // All nodes should have even degree
    // All non-zero degree node should be connected

    // Euler Path: 1
    // Calculate the degree of each node
    // Zero or two nodes can have odd degree and remaining nodes should have even degree
    // All non-zero degree node should be connected

    vector<int> deg(V, 0);
    int odd_deg = 0;

    for (int i = 0; i < V; i++)
    {
        deg[i] = adj[i].size();
        if (deg[i] % 2 != 0)
            odd_deg++;
    }

    if (odd_deg != 2 && odd_deg != 0)
        return 0;

    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (deg[i])
        {
            DFS(i, adj, visited);
            break;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (deg[i] && !visited[i])
            return 0;
    }

    if (odd_deg == 0)
        return 2;
    else
        return 1;
}

int main() {}