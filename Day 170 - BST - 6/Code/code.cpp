#include <iostream>
#include <limits.h>
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q1.
// Method 1:
class Box
{
public:
    bool BST;
    int size, min, max;

    Box(int data)
    {
        BST = 1;
        size = 1;
        min = data;
        max = data;
    }
};

Box *find(Node *root, int &totalSize)
{
    if (!root->left && !root->right)
    {
        totalSize = max(totalSize, 1);
        return new Box(root->data);
    }

    else if (!root->left && root->right)
    {
        Box *head = find(root->right, totalSize);
        if (head->BST && head->min > root->data)
        {
            head->size++;
            head->min = root->data;
            totalSize = max(totalSize, head->size);
            return head;
        }
        else
        {
            head->BST = 0;
            return head;
        }
    }

    else if (root->left && !root->right)
    {
        Box *head = find(root->left, totalSize);
        if (head->BST && head->max < root->data)
        {
            head->size++;
            head->max = root->data;
            totalSize = max(totalSize, head->size);
            return head;
        }
        else
        {
            head->BST = 0;
            return head;
        }
    }

    else
    {
        Box *lefthead = find(root->left, totalSize);
        Box *righthead = find(root->right, totalSize);
        if (lefthead->BST && lefthead->max < root->data && righthead->BST && righthead->min > root->data)
        {
            Box *head = new Box(root->data);
            head->size += lefthead->size + righthead->size;
            head->min = lefthead->min;
            head->max = righthead->max;
            totalSize = max(totalSize, head->size);
            return head;
        }
        else
        {
            lefthead->BST = 0;
            return lefthead;
        }
    }
}
/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    // Your code here
    int totalSize = 0;
    find(root, totalSize);
    return totalSize;
}

// Method 2:
class Box2
{
public:
    bool BST;
    int size, min, max;

    Box2()
    {
        BST = 1;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

Box2 *find2(Node *root, int &totalSize)
{
    if (!root)
    {
        return new Box2();
    }

    Box2 *lefthead = find2(root->left, totalSize);
    Box2 *righthead = find2(root->right, totalSize);

    if (lefthead->BST && righthead->BST && lefthead->max < root->data && righthead->min > root->data)
    {
        Box2 *head = new Box2();
        head->size = 1 + lefthead->size + righthead->size;
        head->min = min(root->data, lefthead->min);
        head->max = max(root->data, righthead->max);
        totalSize = max(totalSize, head->size);
        return head;
    }
    else
    {
        lefthead->BST = 0;
        return lefthead;
    }
}
/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    // Your code here
    int totalSize = 0;
    find2(root, totalSize);
    return totalSize;
}

// Q2.
class Box3
{
public:
    bool BST;
    int sum, min, max;

    Box3()
    {
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

Box3 *find(TreeNode *root, int &totalSum)
{
    if (!root)
    {
        return new Box3();
    }

    Box3 *lefthead = find(root->left, totalSum);
    Box3 *righthead = find(root->right, totalSum);

    if (lefthead->BST && righthead->BST && lefthead->max < root->val && righthead->min > root->val)
    {
        Box3 *head = new Box3();
        head->sum = root->val + lefthead->sum + righthead->sum;
        head->min = min(root->val, lefthead->min);
        head->max = max(root->val, righthead->max);
        totalSum = max(totalSum, head->sum);
        return head;
    }
    else
    {
        lefthead->BST = 0;
        return lefthead;
    }
}

int maxSumBST(TreeNode *root)
{
    int totalSum = 0;
    find(root, totalSum);
    return totalSum;
}

int main() {}