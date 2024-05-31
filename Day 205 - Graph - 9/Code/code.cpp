#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Q1. Prerequisite Tasks.
bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vector<int> adj[N];
    vector<int> indeg(N, 0);

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
        indeg[prerequisites[i].first]++;
    }

    // Kanh's Algo
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!indeg[i])
            q.push(i);
    }
    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (!indeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    return count == N;
}

// Q2. Course Schedule.
vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites)
{
    // code here
    vector<int> adj[N];
    vector<int> indeg(N, 0);

    for (int i = 0; i < P; i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indeg[prerequisites[i][0]]++;
    }

    // Kanh's Algo
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!indeg[i])
            q.push(i);
    }
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (!indeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    vector<int> temp;

    return ans.size() == N ? ans : temp;
}

// Q3. Alien Dictionary.
string findOrder(string dict[], int N, int K)
{
    // code here
    // Adjacency List
    vector<int> adj[K];
    vector<int> indeg(K, 0);

    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
        {
            j++, k++;
        }

        if (j == str1.size())
            continue;

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        indeg[str2[k] - 'a']++;
    }

    // Kanh's Algo

    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (!indeg[i])
            q.push(i);
    }
    string ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        char c = 'a' + node;
        ans += c;

        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (!indeg[adj[node][j]])
                q.push(adj[node][j]);
        }
    }

    return ans;
}

// Q4.
int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    // Adjacency List
    vector<int> adj[n];

    for (int i = 0; i < relations.size(); i++)
    {
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1); // For making them into 0 based indexing.
    }

    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indeg[i])
            q.push(i);
    }

    // Max time to complete previous course
    vector<int> courseTime(n, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (!indeg[adj[node][j]])
                q.push(adj[node][j]);

            courseTime[adj[node][j]] = max(courseTime[adj[node][j]], courseTime[node] + time[node]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, courseTime[i] + time[i]);
    }

    return ans;
}

int main() {}