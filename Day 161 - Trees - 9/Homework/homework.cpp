#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Q1. Postorder Traversal (Iterative).
vector<int> postOrder(Node *root)
{
    // code here
    // We will traverse the tree in the order - N R L.
    vector<int> ans;

    // We will traverse the tree until our root becomes nuLL that shows we have traverse the whole tree.
    while (root)
    {
        // If right of root doesn't exist then we will just go the left side and push the value of the node into the array.
        if (!root->right)
        {
            ans.push_back(root->data);
            root = root->left;
        }
        // If right of root exist:
        else
        {
            // So if the right exist then we have to:
            // first, create a link of the leftmost node to the root node.
            // So that we can come back to root node.
            Node *curr = root->right;
            // We are going to the leftmost node.
            while (curr->left && curr->left != root)
                curr = curr->left;
            // So now there are two conditions:
            // First, that we have not traverse that right [part.
            // Second, we have traverse the right part.

            // Now if we have not traverse the part then the left value of the curr node is NULL.
            // So we will add the value of the node to the ans array.
            // And make a link and go the right.
            if (curr->left == NULL)
            {
                ans.push_back(root->data);
                curr->left = root;
                root = root->right;
            }
            // If we done the traversal then we will simply remove the link and go to left part.
            else
            {
                curr->left = NULL;
                root = root->left;
            }
        }
    }

    // After that we will reverse the ans array.
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {}