#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1. Strongly Connected Components (Kosaraju's Algo).
void topological(int node, vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited)
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            topological(adj[node][j], adj, s, visited);
    }

    s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
            DFS(adj[node][j], adj, visited);
    }
}
// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // Topological Sort
    stack<int> s;
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topological(i, adj, s, visited);
        }
    }

    // Reverse the edges
    vector<vector<int>> adj2(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j];

            adj2[v].push_back(u);
        }
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Pop the node from the stack
    // If it is not visited yet
    // SCC++
    // Call the DFS

    int SCC = 0;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            SCC++;
            DFS(node, adj2, visited);
        }
    }

    return SCC;
}

int main() {}