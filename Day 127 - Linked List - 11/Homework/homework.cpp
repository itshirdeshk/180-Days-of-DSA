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

// Q1. Partition a Linked List around a given value.
struct Node *partition(struct Node *head, int x)
{
    // code here
    Node *head1 = new Node(0);
    Node *head2 = new Node(0);
    Node *head3 = new Node(0);

    Node *tail1 = head1;
    Node *tail2 = head2;
    Node *tail3 = head3;

    Node *temp = head;

    while (temp)
    {
        if (temp->data < x)
        {
            tail1->next = temp;
            temp = temp->next;
            tail1 = tail1->next;
            tail1->next = NULL;
        }
        else if (temp->data == x)
        {
            tail2->next = temp;
            temp = temp->next;
            tail2 = tail2->next;
            tail2->next = NULL;
        }
        else
        {
            tail3->next = temp;
            temp = temp->next;
            tail3 = tail3->next;
            tail3->next = NULL;
        }
    }

    if (head2->next)
    {
        tail1->next = head2->next;
        tail2->next = head3->next;
    }
    else
    {
        tail1->next = head3->next;
    }

    tail1 = head1;
    tail2 = head2;
    tail3 = head3;

    head1 = head1->next;
    head2 = head2->next;
    head3 = head3->next;

    delete tail1;
    delete tail2;
    delete tail3;

    return head1;
}

int main() {}