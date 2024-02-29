#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Q1. Inorder Traversal (Iterative).
vector<int> preOrder(Node *root)
{
    // code here
    stack<Node *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}

// Q2.Postorder Traversal (Iterative)
vector<int> postOrder(Node *root)
{
    // code here
    stack<Node *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Q3. Inorder Traversal (Iterative)
vector<int> inOrder(Node *root)
{
    // code here
    stack<Node *> s;
    stack<bool> visited;

    s.push(root);
    visited.push(0);

    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();

        bool flag = visited.top();
        visited.pop();

        if (!flag)
        {
            if (temp->right)
            {
                s.push(temp->right);
                visited.push(0);
            }
            s.push(temp);
            visited.push(1);
            if (temp->left)
            {
                s.push(temp->left);
                visited.push(0);
            }
        }
        else
        {
            ans.push_back(temp->data);
        }
    }
    return ans;
}

int main() {}