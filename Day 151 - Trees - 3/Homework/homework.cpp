#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Q1. Largest value in each level.
vector<int> largestValues(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;

    if (!root)
        return ans;

    q.push(root);
    int count = 1;
    int maxi = INT_MIN;

    while (!q.empty())
    {
        for (int i = 0; i < count; i++)
        {
            maxi = max(maxi, q.front()->data);
            q.push(q.front());
            q.pop();
        }
        ans.push_back(maxi);

        int count_temp = 0;
        for (int i = 0; i < count; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                count_temp++;
                q.push(temp->left);
            }
            if (temp->right)
            {
                count_temp++;
                q.push(temp->right);
            }
        }
        count = count_temp;
        maxi = INT_MIN;
    }
    return ans;
}