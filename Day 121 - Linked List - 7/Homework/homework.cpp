#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct NodeCDLL
{
    int data;
    struct NodeCDLL *next;
    struct NodeCDLL *prev;

    NodeCDLL(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

int count(Node *head)
{
    int len = 1;
    Node *temp = head;
    while (temp->next != head)
    {

        temp = temp->next;
        len++;
    }
    return len;
}

// Q1. Circular Linked List Traversal.
void printList(struct Node *head)
{
    // code here
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Q2. Check If Circular Linked List.
bool isCircular(Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        if (temp == head)
            return 1;
    }
    return 0;
}

// Q3. Split a Circular Linked List into two halves.
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    int length = count(head);
    int len = (length % 2 == 0) ? (length / 2) : ((length + 1) / 2);
    int pos = 1;
    Node *temp = head;
    *head1_ref = head;
    while (pos < len)
    {
        temp = temp->next;
        pos++;
    }
    *head2_ref = temp->next;
    temp->next = *head1_ref;

    Node *tail = *head2_ref;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    tail->next = *head2_ref;
}

// Q4.
Node *sortedInsert(Node *head, int data)
{
    // Your code here
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        return (head);
    }

    if (head->data >= data)
    {
        Node *t = new Node(data);
        t->next = head;
        Node *p = head;
        Node *q = NULL;
        while (1)
        {
            q = p;
            p = p->next;
            if (p == head)
                break;
        }
        q->next = t;
        head = t;
        return (head);
    }

    Node *p = head;
    Node *q = NULL;
    while (p->data < data)
    {
        q = p;
        p = p->next;
        if (p == head)
            break;
    }
    Node *t = new Node(data);

    q->next = t;
    t->next = p;

    return (head);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // Q5. Create a Circular Singly Linked List and also a Circular Doubly Linked List from the given array below.

    // Circular Singly Linked List
    Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        Node *curr = head;
        if (curr == NULL)
        {
            head = new Node(arr[0]);
            head->next = head;
            curr = head;
        }
        else
        {
            Node *temp = new Node(arr[i]);
            curr->next = temp;
            temp->next = head;
            curr = temp;
        }
    }

    // Circular Doubly Linked List
    NodeCDLL *head1 = NULL;
    for (int i = 0; i < 5; i++)
    {
        NodeCDLL *curr1 = head1;
        if (curr1 == NULL)
        {
            head1 = new NodeCDLL(arr[0]);
            head1->next = head1;
            head1->prev = head1;
            curr1 = head1;
        }
        else
        {
            NodeCDLL *temp = new NodeCDLL(arr[i]);
            temp->next = head1;
            temp->prev = curr1;
            curr1->next = temp;
            head1->prev = temp;
            curr1 = temp;
        }
    }
}