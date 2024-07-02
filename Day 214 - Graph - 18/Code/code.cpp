#include <iostream>
#include <vector>
using namespace std;

// Q1. Circle of strings.
void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}

int isCircle(int N, vector<string> A)
{
    // Creating Edges
    // Adjacency List
    vector<int> adj[26];
    vector<int> inDeg(26, 0);
    vector<int> outDeg(26, 0);

    for (int i = 0; i < N; i++)
    {
        string temp = A[i];
        adj[temp[0] - 'a'].push_back(temp[temp.size() - 1] - 'a');
        outDeg[temp[0] - 'a']++;
        inDeg[temp[temp.size() - 1] - 'a']++;
    }

    // Eulerian Circuit
    // Find Indegree and Outdegree
    for (int i = 0; i < 26; i++)
    {
        if (inDeg[i] != outDeg[i])
            return 0;
    }

    // All the edges are part of one component
    vector<bool> visited(26, 0);
    DFS(A[0][0] - 'a', adj, visited);

    for (int i = 0; i < 26; i++)
    {
        if (inDeg[i] && !visited[i])
            return 0;
    }

    return 1;
}

int main() {}