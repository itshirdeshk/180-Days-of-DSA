#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
using namespace std;

// Q1. Strongly connected component (Tarjans's Algo).
void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, stack<int> &s, vector<bool> &inStack, vector<vector<int>> &ans, int &timer)
{
    visited[node] = 1;
    disc[node] = low[node] = timer;
    s.push(node);
    inStack[node] = 1;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int neigh = adj[node][j];
        if (!visited[neigh])
        {
            timer++;
            DFS(neigh, adj, visited, disc, low, s, inStack, ans, timer);
            low[node] = min(low[node], low[neigh]);
        }
        else
        {
            // If it is present in stack or not
            if (inStack[neigh])
            {
                low[node] = min(low[node], disc[neigh]);
            }
        }
    }

    if (disc[node] == low[node])
    {
        vector<int> temp;
        while (!s.empty() && s.top() != node)
        {
            temp.push_back(s.top());
            inStack[s.top()] = 0;
            s.pop();
        }
        temp.push_back(s.top());
        inStack[s.top()] = 0;
        s.pop();

        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
}

// Function to return a list of lists of integers denoting the members
// of strongly connected components in the given graph.
vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    // code here
    vector<vector<int>> ans;
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, 0);
    stack<int> s;
    vector<bool> inStack(V, 0);
    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, disc, low, s, inStack, ans, timer);
    }

    sort(ans.begin(), ans.end());
    return ans;
}


int main() {}