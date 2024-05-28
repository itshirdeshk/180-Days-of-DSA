#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Q1. Bipartite Graph.
// By using BFS:
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V, -1);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int i = 0; i < adj[node].size(); i++)
                {
                    if (color[adj[node][i]] == -1)
                    {
                        color[adj[node][i]] = (color[node] + 1) % 2;
                        q.push(adj[node][i]);
                    }
                    else
                    {
                        if (color[node] == color[adj[node][i]])
                            return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// By using DFS:
bool check(int node, vector<int> adj[], vector<int> &color)
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (color[adj[node][i]] == -1)
        {
            color[adj[node][i]] = (color[node] + 1) % 2;
            if (!check(adj[node][i], adj, color))
                return 0;
        }
        else
        {
            if (color[adj[node][i]] == color[node])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!check(i, adj, color))
                return 0;
        }
    }
    return 1;
}


int main() {}