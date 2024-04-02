#include <iostream>
#include <bits/stdc++.h>
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

// Q1. Merge two binary Max heaps.
void heapify(vector<int> &ans, int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && ans[left] > ans[largest])
        largest = left;
    if (right < n && ans[right] > ans[largest])
        largest = right;

    if (largest != index)
    {
        swap(ans[largest], ans[index]);
        heapify(ans, largest, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    vector<int> ans;

    for (int i = 0; i < n; i++)
        ans.push_back(a[i]);
    for (int i = 0; i < m; i++)
        ans.push_back(b[i]);

    // convert the array into max heap
    n = ans.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i, n);
    }

    return ans;
}

// Q2. Is Binary Tree Heap.
int count(Node *root)
{
    if (!root)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

bool CBT(Node *root, int index, int n)
{
    if (!root)
        return 1;
    if (index >= n)
        return 0;

    return CBT(root->left, 2 * index + 1, n) && CBT(root->right, 2 * index + 2, n);
}

bool maxheap(Node *root)
{
    if (root->left)
    {
        if (root->data < root->left->data)
            return 0;
        if (!maxheap(root->left))
            return 0;
    }

    if (root->right)
    {
        if (root->data < root->right->data)
            return 0;
        return maxheap(root->right);
    }

    return 1;
}
bool isHeap(struct Node *tree)
{
    // code here

    // count nodes in the tree
    int num = count(tree);
    // CBT hai ya nhi
    if (!CBT(tree, 0, num))
        return 0;
    // Every parent >= child
    return maxheap(tree);
}

// Q3. BST to max heap.
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void postorder(Node *root, vector<int> &ans, int &index)
{
    if (!root)
        return;

    postorder(root->left, ans, index);
    postorder(root->right, ans, index);
    root->data = ans[index++];
}

void convertToMaxHeapUtil(Node *root)
{
    // Your code goes here
    // inorder traversal
    vector<int> ans;
    inorder(root, ans);
    // post order traversal
    int index = 0;
    postorder(root, ans, index);
}

int main() {}