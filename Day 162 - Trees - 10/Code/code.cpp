#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Q1. Burning Tree.
int Burn(Node *root, int &timer, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        return -1;

    int left = Burn(root->left, timer, target);
    int right = Burn(root->right, timer, target);

    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }
    if (right < 0)
    {
        timer = max(timer, left + abs(right));
        return right - 1;
    }

    return 1 + max(left, right);
}

void find(Node *root, int target, Node *&BurnNode)
{
    if (!root)
        return;

    if (root->data == target)
    {
        BurnNode = root;
        return;
    }

    find(root->left, target, BurnNode);
    find(root->right, target, BurnNode);
}

int Height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(Height(root->left), Height(root->right));
}

int minTime(Node *root, int target)
{
    // Your code goes here
    int timer = 0;
    Burn(root, timer, target);

    // Height of target node
    Node *BurnNode = NULL;
    find(root, target, BurnNode);

    int high = Height(BurnNode) - 1;

    return max(timer, high);
}

// Q2. Maximum Path Sum between 2 Special Nodes.
int pathSum(Node *root, int &sum)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return root->data;

    int left = pathSum(root->left, sum);
    int right = pathSum(root->right, sum);

    if (root->left && root->right)
    {
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }

    if (root->left)
        return root->data + left;
    if (root->right)
        return root->data + right;
}

int maxPathSum(Node *root)
{
    // code here
    int sum = INT_MIN;
    int value = pathSum(root, sum);

    if (root->left && root->right)
        return sum;
    return max(sum, value);
}

int main() {}