#include <iostream>
#include <vector>
#include <queue>
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

Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;
    Node *temp = new Node(x);
    cout << "Enter the Left child value of " << x << " :\t";
    temp->left = BinaryTree();
    cout << "Enter the Right child value of " << x << " :\t";
    temp->right = BinaryTree();
    return temp;
}

// Tree Traversal
void preorder(Node *root)
{
    if (root == NULL)
        return;
    // N L R
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    // L N R
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    // L R N
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

vector<int> levelOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return ans;
}

int main()
{
    cout << "Enter the Root Node value :\t";
    Node *root;
    root = BinaryTree();

    cout << "Preorder :" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder :" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder :" << endl;
    postorder(root);
}