#include <iostream>
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

Node *insert(Node *root, int target)
{
    if (!root)
    {
        Node *temp = new Node(target);
        return temp;
    }

    if (target < root->data)
        root->left = insert(root->left, target);
    else
        root->right = insert(root->right, target);

    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node *root, int target)
{
    if (!root)
        return 0;
    if (root->data == target)
        return 1;
    if (root->data > target)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// Delete a node from BST.
Node *deleteNode(Node *root, int target)
{
    // your code goes here
    if (!root)
        return NULL;
    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (root->data < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }

    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // Find the greatest element of the left
            Node *child = root->left;
            Node *parent = root;

            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main()
{
    int arr[] = {6, 3, 11, 5, 7, 8};

    Node *root = NULL;
    for (int i = 0; i < 6; i++)
        root = insert(root, arr[i]);

    // inorder(root);
    // cout<<search(root, 10);
}