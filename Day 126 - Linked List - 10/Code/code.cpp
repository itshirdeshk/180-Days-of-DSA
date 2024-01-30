#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *head1, Node *head2)
{
    Node *head = new Node(0);
    Node *tail = head;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->bottom = head1;
            head1 = head1->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
        else
        {
            tail->bottom = head2;
            head2 = head2->bottom;
            tail = tail->bottom;
            tail->bottom = NULL;
        }
    }

    if (head1)
        tail->bottom = head1;
    else
        tail->bottom = head2;

    tail = head;
    head = head->bottom;
    delete tail;
    return head;
}

void mergeSort(Node *arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    arr[start] = merge(arr[start], arr[mid + 1]);
}

// Q1. Flattening a Linked List.
Node *flatten(Node *root)
{
    // Your code here
    Node *head1, *head2, *head3;

    while (root->next)
    {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        head1->next = NULL;
        head2->next = NULL;

        root = merge(head1, head2);

        root->next = head3;
    }
    return root;
}

// Q2. Merge K sorted linked lists.
// Method 1:
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    Node *head = arr[0];
    for (int i = 1; i < K; i++)
    {
        head = merge(head, arr[i]);
    }

    return head;
}

// Method 2:
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    mergeSort(arr, 0, K - 1);
    return arr[0];
}

int main() {}