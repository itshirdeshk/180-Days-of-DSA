#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. BFS of graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    queue<int> q;
    q.push(0);
    vector<bool> visited(V, 0);
    visited[0] = 1;

    vector<int> ans;
    int node;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}

// Q2. DFS of graph.
// Method 1: By using recursion.
void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, 0);
    vector<int> ans;
    DFS(0, adj, visited, ans);
    return ans;
}

// Method 2: By using Stack.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, 0);
    vector<int> ans;
    stack<int> s;
    s.push(0);

    int node;
    while (!s.empty())
    {
        node = s.top();
        s.pop();
        if (!visited[node])
        {
            visited[node] = 1;
            ans.push_back(node);
            for (int i = adj[node].size() - 1; i >= 0; i--)
            {
                s.push(adj[node][i]);
            }
        }
    }
    return ans;
}


int main() {}