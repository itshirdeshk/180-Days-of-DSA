#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Implementing Dijkstra Algorithm.
// Method 1:
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool> explore(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;

    // Select a node which is not explored yet and its distance value is min.
    int count = V;
    while (count--)
    {
        int node = -1, value = INT_MAX;

        for (int i = 0; i < V; i++)
        {
            if (!explore[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }

        explore[node] = 1;

        // Relax the edges.
        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i][0];
            int weight = adj[node][i][1];

            if (!explore[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
            }
        }
    }
    return dist;
}

// Method 2:
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool> explore(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, S});

    // Select a node which is not explored yet and its distance value is min.

    while (!p.empty())
    {
        int node = p.top().second;
        p.pop();

        if (explore[node] == 1)
            continue;

        explore[node] = 1;

        // Relax the edges.
        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i][0];
            int weight = adj[node][i][1];

            if (!explore[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour], neighbour});
            }
        }
    }
    return dist;
}

int main() {}