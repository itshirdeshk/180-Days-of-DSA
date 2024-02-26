#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

// Q1. Determine if Two Trees are Identical.
bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
    if (r1 == NULL && r2 == NULL)
        return 1;
    if ((!r1 && r2) || (r1 && !r2))
        return 0;
    if (r1->data != r2->data)
        return 0;
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

// Q2. Mirror Tree.
void mirror(Node *root)
{
    // code here
    if (!root)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

// Q3. Check for Balanced Tree.
int height(Node *root, bool &valid)
{
    if (!root)
        return 0;

    int L = height(root->left, valid);
    if (valid)
    {
        int R = height(root->right, valid);
        if (abs(L - R) > 1)
            valid = 0;
        return 1 + max(L, R);
    }
    return -1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    bool valid = 1;
    height(root, valid);
    return valid;
}

// Q4. Level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    // Your code here
    stack<Node *> s1; // R to L
    stack<Node *> s2; // L to R

    s1.push(root);
    vector<int> ans;

    while (!s1.empty() || !s2.empty())
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if (temp->right)
                    s2.push(temp->right);
                if (temp->left)
                    s2.push(temp->left);
            }
        }
        else
        {
            while (!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if (temp->left)
                    s1.push(temp->left);
                if (temp->right)
                    s1.push(temp->right);
            }
        }
    }
    return ans;
}

// Q5. Check if two Nodes are Cousins.
bool parent(Node *root, int a, int b)
{
    if (root == NULL)
        return 0;
    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b)
            return 1;
        if (root->left->data == b && root->right->data == a)
            return 1;
    }
    return (parent(root->left, a, b) || parent(root->right, a, b));
}

bool isCousins(Node *root, int a, int b)
{
    // add code here.
    // Find the level
    queue<Node *> q;
    q.push(root);

    int l1 = -1, l2 = -1;
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == a)
                l1 = level;
            if (temp->data == b)
                l2 = level;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        level++;
        if (l1 != l2)
            return 0;
        if (l1 != -1)
            break;
    }
    return !parent(root, a, b);
}

int main() {}