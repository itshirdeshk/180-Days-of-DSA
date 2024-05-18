#include <iostream>
#include <vector>
using namespace std;

// int main()
// {
//     int vertex, edges;
//     cin >> vertex >> edges;

//     // Adjacency matrix
//     // Undirected or Directed Unweighted Graph
//     vector<vector<bool>> AdjMat(vertex, vector<bool>(vertex, 0));
//     // Undirected or Directed Weighted Graph
//     vector<vector<int>> AdjMat(vertex, vector<int>(vertex, 0));

//     int u, v, weight;
//     for (int i = 0; i < edges; i++)
//     {
//         // Undirected Unweighted Graph
//         cin >> u >> v;
//         AdjMat[u][v] = 1;
//         AdjMat[v][u] = 1;
//         // Undirected Weighted Graph
//         cin >> u >> v >> weight;
//         AdjMat[u][v] = weight;
//         AdjMat[v][u] = weight;

//         // Directed Unweighted Graph
//         cin >> u >> v;
//         AdjMat[u][v] = 1;
//         // Directed Weighted Graph
//         cin >> u >> v >> weight;
//         AdjMat[u][v] = weight;

//     }

//     for (int i = 0; i < vertex; i++)
//     {
//         for (int j = 0; j < vertex; j++)
//         {
//             cout << AdjMat[i][j] << " ";
//         }
//         cout << endl;
//     }

// }

int main()
{
    // Adjacency List
    int vertex, edges;
    cin >> vertex >> edges;

    // Undirected or directed unweighted graph
    // vector<int> AdjList[vertex];
    // Undirected or directed weighted graph
    vector<pair<int, int>> AdjList[vertex];

    // Undirected unweighted graph
    // int u, v;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v;

    //     AdjList[u].push_back(v);
    //     AdjList[v].push_back(u);
    // }

    // Directed unweighted graph
    // int u, v;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v;

    //     AdjList[u].push_back(v);
    // }
    // Undirected weighted graph
    // int u, v, weight;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v >> weight;

    //     AdjList[u].push_back(make_pair(v, weight));
    //     AdjList[v].push_back(make_pair(u, weight));
    // }

    // Directed weighted graph
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;

        AdjList[u].push_back(make_pair(v, weight));
    }

    // Print the list
    // Undirected unweighted graph
    // for (int i = 0; i < vertex; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < AdjList[i].size(); j++)
    //     {
    //         cout << AdjList[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Undirected weighted graph
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << AdjList[i][j].first << " " << AdjList[i][j].second<<" | ";
        }
        cout << endl;
    }
}
