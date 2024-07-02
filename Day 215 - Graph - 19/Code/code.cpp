#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    vector<bool> isMST(V, 0);

    vector<int> parent(V);

    int cost = 0;

    p.push({0, {0, -1}});

    while (!p.empty())
    {
        int wt = p.top().first;
        int node = p.top().second.first;
        int par = p.top().second.second;

        p.pop();

        if (!isMST[node])
        {
            isMST[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++)
            {
                if (!isMST[adj[node][j][0]])
                {
                    p.push({adj[node][j][1], {adj[node][j][0], node}});
                }
            }
        }
    }

    return cost;
}

int main() {}