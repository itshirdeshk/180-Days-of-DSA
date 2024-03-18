#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int value)
    {
        data = value;
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

Node *insert(Node *root, int key)
{
    // Doesn't exist
    if (!root)
        return new Node(key);

    // Exist
    if (key < root->data)
    {
        root->left = insert(root -> left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root -> right, key);
    }
    else
    {
        // Duplicate elements are not allowed
        return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Balancing check
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->data)
        return rightRotation(root);
    // Right Right Case
    else if (balance < -1 && root->right->data < key)
        return leftRotation(root);
    // Left Right Case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left Case
    else if (balance < -1 && root->right->data > key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalancing
    else
        return root;
}

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);

    cout << "Preorder: ";
    preorder(root);

    cout<<endl;

    cout << "Inorder: ";
    inorder(root);
}