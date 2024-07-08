#include <iostream>
#include <vector>
using namespace std;

// Q1. Articulation Point - I.
void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artpoint, int &timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;
    int child = 0;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neib = adj[node][j];
        if (neib == parent)
            continue;
        else if (visited[neib])
        {
            low[node] = min(low[node], disc[neib]);
        }
        else
        {
            child++;
            timer++;
            DFS(neib, node, adj, visited, disc, low, artpoint, timer);

            if (disc[node] <= low[neib] && parent != -1)
            {
                artpoint[node] = 1;
            }

            low[node] = min(low[node], low[neib]);
        }
    }

    if (child > 1 && parent == -1)
    {
        artpoint[node] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    // Code here
    vector<bool> artpoint(V, 0);
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, 0);
    int timer = 0;

    DFS(0, -1, adj, visited, disc, low, artpoint, timer);

    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (artpoint[i])
            ans.push_back(i);
    }

    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

int main() {}