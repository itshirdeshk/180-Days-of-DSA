#include <iostream>
#include <vector>
using namespace std;

// Q1. Distance from the Source (Bellman-Ford Algorithm).
vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    int e = edges.size();

    for (int i = 0; i < V - 1; i++)
    {
        bool flag = 0;
        // Relax all the edges
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] == 1e8)
                continue;

            if (dist[u] + weight < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + weight;
            }
        }

        if (!flag)
            return dist;
    }

    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] == 1e8)
            continue;

        if (dist[u] + weight < dist[v])
        {
            // cycle detected
            vector<int> ans(1, -1);
            return ans;
        }
    }

    return dist;
}

int main() {}