#include <iostream>
#include <queue>
#include <vector>
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

// Q1. Level order traversal.
vector<int> levelOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}

// Q2. Size of Binary Tree.
// Method 1:
void total(Node *root, int &count)
{
    if (root == NULL)
        return;
    count++;
    total(root->left, count);
    total(root->right, count);
}

// Method 2:
int totalNode(Node *root)
{
    // Your code here
    if (root == NULL)
        return 0;
    return (1 + totalNode(root->left) + totalNode(root->right));
}

// Q3.Sum of Binary Tree.
// Method 1:
void totalSum(Node *root, long int &sum)
{
    if (!root)
        return;
    sum += root->data;
    totalSum(root->left, sum);
    totalSum(root->right, sum);
}

// Method 2:
long int sumBT(Node *root)
{
    // Code here
    if (root == NULL)
        return 0;
    return (root->data + sumBT(root->left) + sumBT(root->right));
}

// Q4. Count Leaves in Binary Tree.
// Method 1:
void countLeaf(Node *root, int &count)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        count++;
        return;
    }
    countLeaf(root->left, count);
    countLeaf(root->right, count);
}

// Method 2:
int countLeaves(Node *root)
{
    // Your code here
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
    {
        return 1;
    }
    return (countLeaves(root->left) + countLeaves(root->right));
}

// Q5. Count Non-Leaf Nodes in Tree.
int countNonLeafNodes(Node *root)
{
    // Code here
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 0;
    return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
}

// Q6. Height of Binary Tree.
int height(struct Node *root)
{
    // code here
    if (root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}


int main() {}