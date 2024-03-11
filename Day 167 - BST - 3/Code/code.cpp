#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

// Q1. Construct Binary Search Tree from Preorder Traversal.
TreeNode *BST(vector<int> &preorder, int &index, int lower, int upper)
{
    if (index == preorder.size() || preorder[index] < lower || preorder[index] > upper)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = BST(preorder, index, lower, root->val);
    root->right = BST(preorder, index, root->val, upper);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return BST(preorder, index, INT_MIN, INT_MAX);
}

// Q2. Construct BST from Postorder.
Node *BST(int post[], int &index, int lower, int upper)
{
    if (index < 0 || post[index] < lower || post[index] > upper)
        return NULL;

    Node *root = new Node(post[index--]);
    root->right = BST(post, index, root->data, upper);
    root->left = BST(post, index, lower, root->data);
    return root;
}

Node *constructTree(int post[], int size)
{
    // code here
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}

// Q3. Preorder Traversal and BST.
// Method 1:
void BST(int arr[], int &index, int lower, int upper, int &N)
{
    if (index == N || arr[index] < lower || arr[index] > upper)
        return;

    int value = arr[index++];
    BST(arr, index, lower, value, N);
    BST(arr, index, value, upper, N);
}
int canRepresentBST(int arr[], int N)
{
    // code here
    int index = 0;
    BST(arr, index, INT_MIN, INT_MAX, N);

    return index == N;
}

// Method 2:
int canRepresentBST(int arr[], int N)
{
    // code here
    stack<int> lower, upper;
    lower.push(INT_MIN);
    upper.push(INT_MAX);
    int left, right;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < lower.top())
            return 0;

        while (arr[i] > upper.top())
        {
            upper.pop();
            lower.pop();
        }

        left = lower.top();
        right = upper.top();

        upper.pop();
        lower.pop();

        // Right side
        lower.push(arr[i]);
        upper.push(right);

        // Left side
        lower.push(left);
        upper.push(arr[i]);
    }
    return 1;
}

int main() {}