#include <iostream>
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

// Q1. Construct Tree from Inorder & Preorder.
int find(int in[], int target, int inStart, int inEnd)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node *Tree(int in[], int pre[], int inStart, int inEnd, int index)
{
    if (inStart > inEnd)
        return NULL;
    Node *root = new Node(pre[index]);
    int pos = find(in, pre[index], inStart, inEnd);
    root->left = Tree(in, pre, inStart, pos - 1, index + 1);
    root->right = Tree(in, pre, pos + 1, inEnd, index + (pos - inStart) + 1);
    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    Node *root = Tree(in, pre, 0, n - 1, 0);
    return root;
}

// Q2. Tree from Postorder and Inorder.
int find(int in[], int target, int inStart, int inEnd)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node *Tree(int in[], int post[], int inStart, int inEnd, int index)
{
    if (inStart > inEnd)
        return NULL;
    Node *root = new Node(post[index]);
    int pos = find(in, post[index], inStart, inEnd);
    root->right = Tree(in, post, pos + 1, inEnd, index - 1);
    root->left = Tree(in, post, inStart, pos - 1, index - (inEnd - pos) - 1);
    return root;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    Node *root = Tree(in, post, 0, n - 1, n - 1);
    return root;
}

int main() {}