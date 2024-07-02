#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Minimum Spanning Tree.
int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // Priority Queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            p.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }

    int cost = 0;
    int edges = 0;
    while (!p.empty())
    {
        int wt = p.top().first;
        int u = p.top().second.first;
        int v = p.top().second.second;
        p.pop();

        if (findParent(u, parent) != findParent(v, parent))
        {
            cost += wt;
            unionByRank(u, v, parent, rank);
            edges++;
        }

        if (edges == V - 1)
            break;
    }

    return cost;
}

int main() {}