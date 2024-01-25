#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Q1. Given an array, convert it into a doubly linked List by inserting each element at the start of the Doubly Linked List. Solve the problem iteratively and Recursively.

// Recursively:
Node *createDLL(int arr[], int index, int size, Node *curr)
{
    if (index == size)
    {
        curr->prev = NULL;
        return curr;
    }

    Node *temp = new Node(arr[index]);
    if (curr)
    {
        temp->next = curr;
        curr->prev = temp;
    }
    else
    {
        temp->next = curr;
    }
    return createDLL(arr, index + 1, size, temp);
}

// Q2. Doubly linked list Insertion at given position.
void addNode(Node *head, int pos, int data)
{
    // Your code here
    Node *curr = head;
    while (pos--)
    {
        curr = curr->next;
    }
    // Insert at end
    if (curr->next == NULL)
    {
        Node *temp = new Node(data);
        temp->prev = curr;
        curr->next = temp;
    }
    // Insert at middle
    else
    {
        Node *temp = new Node(data);
        temp->next = curr->next;
        temp->prev = curr;
        curr->next = temp;
        temp->next->prev = temp;
    }
}

// Q3. Reverse a Doubly Linked List.
Node *reverseDLL(Node *head)
{
    // Your code here
    if (head->next == NULL)
        return head;

    Node *curr = head, *prev = NULL, *fut = NULL;
    while (curr)
    {
        fut = curr->next;
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    head = prev;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    Node *head = NULL;

    // Iteratively:
    for (int i = 0; i < 5; i++)
    {
        if (!head)
        {
            head = new Node(arr[i]);
        }
        else
        {
            Node *temp = new Node(arr[i]);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    head = createDLL(arr, 0, 5, head);

    Node *temp = head;
    while (head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}