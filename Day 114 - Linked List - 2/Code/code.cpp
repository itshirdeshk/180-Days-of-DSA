#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *createLL(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLL(arr, index + 1, size);
    return temp;
}

// Delete a node of a particular posiiton
// Method 1:
void deleteNode(Node *&Head, Node *curr, Node *prev, int x, int index)
{
    if (x == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
        return;
    }

    if (index == x)
    {
        prev->next = curr->next;
        delete curr;
        return;
    }

    deleteNode(Head, curr->next, curr, x, index + 1);
}

// Method 2:
Node* deleteNode(Node *curr, int x){
    if(x == 1){
        Node *temp = curr->next;
        delete curr;
        return temp;
    }

    curr->next = deleteNode(curr->next, x - 1);
    return curr;
}

int main()
{
    Node *Head = NULL;
    int arr[] = {1, 2, 3, 4, 5};

    Head = createLL(arr, 0, 5);

    // Delete a Node at start

    if(Head != NULL){
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }

    // Delete a Node at end

    if (Head != NULL)
    {
        if (Head->next == NULL)
        {
            Node *temp = Head;
            Head = NULL;
            delete temp;
        }
        else
        {
            Node *curr = Head;
            Node *prev = NULL;
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }

            delete curr;
            prev->next = NULL;
        }
    }

    // Delete a node of a particular posiiton
    Node *curr = Head;
    Node *prev = NULL;

    deleteNode(Head, curr, prev, 3, 1);
    deleteNode(Head, curr, prev, 1, 1);

    while (Head)
    {
        cout << Head->data << " ";
        Head = Head->next;
    }

}