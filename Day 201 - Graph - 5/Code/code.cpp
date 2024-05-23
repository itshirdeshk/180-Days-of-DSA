#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

// Q1. Topological sort.
// By using DFS:
void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited, s);
    }

    s.push(node);
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, 0);
    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, s);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// By using BFS - Kahn's Algo:
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    vector<int> inDeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDeg[adj[i][j]]++;
        }
    }

    // Push all the nodes of zero indegree in queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!inDeg[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            inDeg[adj[node][i]]--;
            if (inDeg[adj[node][i]] == 0)
                q.push(adj[node][i]);
        }
    }

    return ans;
}

int main() {}