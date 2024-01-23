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

Node *createDLL(int arr[], int index, int size, Node *back)
{
    if (index == size)
        return NULL;

    Node *temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = createDLL(arr, index + 1, size, temp);
    return temp;
}

int main()
{
    // Node *head = NULL;

    // Create Doubly Linked List
    int arr[] = {1, 2, 3, 4, 5};

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (!head)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    // Insert at start
    if (head == NULL)
    {
        head = new Node(5);
    }
    else
    {
        Node *temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // Insert at end
    if (!head)
    {
        head = new Node(5);
    }
    else
    {
        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        Node *temp = new Node(5);
        curr->next = temp;
        temp->prev = curr;
    }

    // Insert at a particular position
    int pos = 2;

    // Insert at start
    if (pos == 0)
    {
        if (!head)
            head = new Node(5);
        else
        {
            Node *temp = new Node(5);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    else
    {
        Node *curr = head;
        while (--pos)
        {
            curr = curr->next;
        }
        // Insert at end
        if (curr->next == NULL)
        {
            Node *temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }
        // Insert at middle
        else
        {
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }

    // Delete a Node at start
    if (head)
    {
        // If only one node exist
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than one node exist
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            if (head)
                head->prev = NULL;
        }
    }

    // Delete a Node at end
    if (head)
    {
        // If only one node exist
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than one node exist
        else
        {
            Node *curr = head;
            while (curr->next)
                curr = curr->next;

            curr->prev->next = NULL;
            delete curr;
        }
    }

    // Delete a node at a particular position
    int pos = 3;

    // Delete at start
    if (pos == 1)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than one node exist
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            if (head)
                head->prev = NULL;
        }
    }
    else
    {
        Node *curr = head;
        while (--pos)
            curr = curr->next;
        // Delete at end
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;
            delete curr;
        }
        // Delete at middle
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }

    Node *trav = head;
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}