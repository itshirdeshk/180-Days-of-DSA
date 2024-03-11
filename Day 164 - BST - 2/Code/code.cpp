#include <iostream>
#include <vector>
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

// Q1. Check for BST.
// Method 1:
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
// Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    // Your code here
    vector<int> ans;
    inorder(root, ans);

    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])
            return 0;
    }

    return 1;
}

// Method 2:
bool BST(Node *root, int &prev)
{
    if (!root)
        return 1;

    if (!BST(root->left, prev))
        return 0;

    if (root->data <= prev)
        return 0;

    prev = root->data;
    return BST(root->right, prev);
}

// Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    // Your code here
    int prev = INT_MIN;
    return BST(root, prev);
}

// Q2. Minimum Distance Between BST Nodes.
void minDist(Node *root, int &prev, int &ans)
{
    if (!root)
        return;
    minDist(root->left, prev, ans);
    if (prev != INT_MIN)
        ans = min(ans, root->data - prev);
    prev = root->data;
    minDist(root->right, prev, ans);
}

int minDiffInBST(Node *root)
{
    int prev = INT_MIN;
    int ans = INT_MAX;
    minDist(root, prev, ans);
    return ans;
}

// Q3. Sum of k smallest elements in BST.
void kSum(Node *root, int &sum, int &k)
{
    if (!root)
        return;
    kSum(root->left, sum, k);
    k--;
    if (k >= 0)
        sum += root->data;
    if (k < 0)
        return;
    kSum(root->right, sum, k);
}

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
int sum(Node *root, int k)
{

    // Your code here
    int sum = 0;
    kSum(root, sum, k);
    return sum;
}

// Q4. Kth largest element in BST.
void kLargest(Node *root, int &ans, int &k)
{
    if (!root)
        return;
    kLargest(root->right, ans, k);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }

    kLargest(root->left, ans, k);
}

int kthLargest(Node *root, int K)
{
    // Your code here
    int ans;
    kLargest(root, ans, K);
    return ans;
}

// Q5. Array to BST.
void ArrayToBST(vector<int> &arr, int start, int end, vector<int> &ans)
{
    if (start > end)
        return;

    int mid = start + (end - start) / 2;
    ans.push_back(arr[mid]);
    ArrayToBST(arr, start, mid - 1, ans);
    ArrayToBST(arr, mid + 1, end, ans);
}

vector<int> sortedArrayToBST(vector<int> &nums)
{
    // Code here
    vector<int> ans;
    ArrayToBST(nums, 0, nums.size() - 1, ans);
    return ans;
}

int main() {}