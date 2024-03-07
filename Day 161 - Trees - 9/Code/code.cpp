#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Q1. Inorder Traversal (Iterative).
vector<int> inOrder(Node *root)
{
    // code here
    vector<int> ans;
    while (root)
    {
        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
                curr = curr->right;
            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }
    return ans;
}

// Q2. Preorder traversal (Iterative).
vector<int> preOrder(Node *root)
{
    // code here
    vector<int> ans;
    while (root)
    {
        if (!root->left)
        {
            ans.push_back(root->data);
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
                curr = curr->right;
            if (curr->right == NULL)
            {
                ans.push_back(root->data);
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}

// Q3. Flatten binary tree to linked list.
void flatten(Node *root)
{
    // code here
    while (root)
    {
        if (!root->left)
        {
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right)
                curr = curr->right;
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}



int main() {}