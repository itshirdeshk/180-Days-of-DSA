#include <iostream>
#include <queue>
#include <vector>
#include<limits.h>
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

// Q1. Left View of Binary Tree.
// Method 1:
vector<int> leftView(Node *root)
{
    // Your code here
    queue<Node *> q;
    vector<int> ans;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
// Method 2:
void LView(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    LView(root->left, level + 1, ans);
    LView(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root)
        return ans;

    LView(root, 0, ans);
    return ans;
}

// Q2. Right View of Binary Tree.
// Method 1:
vector<int> rightView(Node *root)
{
    // Your Code here
    queue<Node *> q;
    vector<int> ans;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        ans.push_back(q.front()->data);
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    return ans;
}

// Method 2:
void LView(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    LView(root->right, level + 1, ans);
    LView(root->left, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root)
        return ans;

    LView(root, 0, ans);
    return ans;
}

// Q3.
// Method 1:
void find(Node *root, int pos, int &l, int &r)
{
    if (!root)
        return;
    l = min(l, pos);
    r = max(r, pos);

    find(root->left, pos - 1, l, r);
    find(root->right, pos + 1, l, r);
}

vector<int> topView(Node *root)
{
    // Your code here
    int l = 0, r = 0;
    find(root, 0, l, r);
    vector<int> ans(r - l + 1);
    vector<bool> filled(r - l + 1, 0);
    queue<Node *> q;
    queue<int> index;
    q.push(root);
    index.push(-1 * l);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        if (!filled[pos])
        {
            filled[pos] = 1;
            ans[pos] = temp->data;
        }
        if (temp->left)
        {
            q.push(temp->left);
            index.push(pos - 1);
        }
        if (temp->right)
        {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }
    return ans;
}

// Method 2:
void Tview(Node *root, int pos, vector<int> &ans, vector<int> &level, int l)
{
    if (!root)
        return;
    if (level[pos] > l)
    {
        ans[pos] = root->data;
        level[pos] = l;
    }
    Tview(root->left, pos - 1, ans, level, l + 1);
    Tview(root->right, pos + 1, ans, level, l + 1);
}

vector<int> topView(Node *root)
{
    // Your code here
    int l = 0, r = 0;
    find(root, 0, l, r);
    vector<int> ans(r - l + 1);
    vector<int> level(r - l + 1, INT_MAX);
    Tview(root, -1 * l, ans, level, 0);
    return ans;
}


int main() {}