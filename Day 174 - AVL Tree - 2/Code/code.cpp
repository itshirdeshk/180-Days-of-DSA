#include <iostream>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int getheight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}

int getBalance(Node *root)
{
    return (getheight(root->left) - getheight(root->right));
}

// Right Rotation
Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;
}

Node *deleteNode(Node *root, int key)
{
    // add code here,
    if (!root)
        return NULL;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Only one child exist
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Both child exists
        else
        {
            // Right side smallest element
            Node *curr = root->right;
            while (curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // Update the height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Check the balancing
    int balance = getBalance(root);

    if (balance > 1)
    {
        // LL
        if (getBalance(root->left) >= 0)
        {
            rightRotation(root);
        }
        // LR
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if (balance < -1)
    {
        // RR
        if (getBalance(root->right) <= 0)
        {
            leftRotation(root);
        }
        // RL
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else
    {
        return root;
    }
}


