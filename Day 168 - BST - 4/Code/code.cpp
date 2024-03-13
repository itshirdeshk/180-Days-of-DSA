#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// Q1. Lowest Common Ancestor in a BST.
Node *LCA(Node *root, int n1, int n2)
{
    // code here
    if (!root)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else
        return root;
}

// Q2. Print BST elements in given range.
void find(Node *root, vector<int> &ans, int &low, int &high)
{
    if (!root)
        return;
    if (root->data > low && root->data > high)
        find(root->left, ans, low, high);
    else if (root->data < low && root->data < high)
        find(root->right, ans, low, high);
    else
    {
        find(root->left, ans, low, high);
        ans.push_back(root->data);
        find(root->right, ans, low, high);
    }
}

vector<int> printNearNodes(Node *root, int low, int high)
{
    // code here
    vector<int> ans;
    find(root, ans, low, high);
    return ans;
}

// Q3. Check whether BST contains Dead End.
bool dead(Node *root, int lower, int upper)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
    {
        if (root->data - lower == 1 && upper - root->data == 1)
            return 1;
        else
            return 0;
    }
    return (dead(root->left, lower, root->data) || dead(root->right, root->data, upper));
}

bool isDeadEnd(Node *root)
{
    // Your code here
    return dead(root, 0, INT_MAX);
}

// Q4. Find Common Nodes in two BSTs.
vector<int> findCommon(Node *root1, Node *root2)
{
    // Your code here
    vector<int> ans;
    stack<Node *> s1;
    stack<Node *> s2;

    while (root1)
    {
        s1.push(root1);
        root1 = root1->left;
    }
    while (root2)
    {
        s2.push(root2);
        root2 = root2->left;
    }

    while (!s1.empty() && !s2.empty())
    {
        if (s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);
            root1 = s1.top()->right;
            s1.pop();
            root2 = s2.top()->right;
            s2.pop();
        }

        else if (s1.top()->data > s2.top()->data)
        {
            root2 = s2.top()->right;
            s2.pop();
        }
        else
        {
            root1 = s1.top()->right;
            s1.pop();
        }

        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
    }
    return ans;
}


int main() {}