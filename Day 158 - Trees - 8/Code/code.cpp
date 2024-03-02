#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Q1. Vertical Traversal of Binary Tree.
void find(Node *root, int pos, int &l, int &r)
{
    if (root == NULL)
        return;

    l = min(pos, l);
    r = max(pos, r);
    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}
// Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(Node *root)
{
    // Your code here
    int l = 0, r = 0;
    find(root, 0, l, r);
    vector<vector<int>> pos(r + 1);
    vector<vector<int>> neg(abs(l) + 1);
    queue<Node *> q;
    queue<int> index;
    q.push(root);
    index.push(0);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int posi = index.front();
        index.pop();

        if (posi >= 0)
            pos[posi].push_back(temp->data);
        if (posi < 0)
            neg[abs(posi)].push_back(temp->data);

        if (temp->left)
        {
            q.push(temp->left);
            index.push(posi - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(posi + 1);
        }
    }

    vector<int> ans;

    for (int i = neg.size() - 1; i > 0; i--)
        for (int j = 0; j < neg[i].size(); j++)
            ans.push_back(neg[i][j]);

    for (int i = 0; i < pos.size(); i++)
        for (int j = 0; j < pos[i].size(); j++)
            ans.push_back(pos[i][j]);

    return ans;
}

// Q2. Diagonal Traversal of Binary Tree.
void find(Node *root, int pos, int &l)
{
    if (!root)
        return;
    l = max(l, pos);

    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDig(Node *root, int pos, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;
    ans[pos].push_back(root->data);
    findDig(root->left, pos + 1, ans);
    findDig(root->right, pos, ans);
}

vector<int> diagonal(Node *root)
{
    // your code here
    int l = 0;
    find(root, 0, l);

    vector<vector<int>> ans(l + 1);
    findDig(root, 0, ans);

    vector<int> temp;
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
            temp.push_back(ans[i][j]);

    return temp;
}

// Q3. Boundary Traversal of binary tree.+
void leftSub(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    ans.push_back(root->data);
    if (root->left)
        leftSub(root->left, ans);
    else
        leftSub(root->right, ans);
}

void leaf(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
    }

    leaf(root->left, ans);
    leaf(root->right, ans);
}

void rightSub(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        rightSub(root->right, ans);
    else
        rightSub(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> ans;

    // Root Element
    ans.push_back(root->data);

    // Left Boundary Element
    leftSub(root->left, ans);

    // Leaf Nodes
    if (root->left || root->right)
        leaf(root, ans);

    // Right Boundary Elements in reverse order
    rightSub(root->right, ans);

    return ans;
}

int main() {}