#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Shortest Path in Weighted undirected graph.
vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
{
    // Code here
    // Adjacency List
    vector<pair<int, int>> adj[V + 1];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // Dijkstra's Algo
    vector<bool> explore(V + 1, 0);
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, 1});
    dist[1] = 0;

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if (explore[node] == 1)
            continue;
        explore[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j].first;
            int weight = adj[node][j].second;
            if (!explore[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
                parent[neighbour] = node;
            }
        }
    }

    vector<int> path;

    if (parent[V] == -1)
    {
        path.push_back(-1);
        return path;
    }

    int dest = V;
    while (dest != -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    path.push_back(dist[V]);
    reverse(path.begin(), path.end());

    return path;
}

int main() {}