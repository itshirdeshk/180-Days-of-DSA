#include <iostream>
#include <vector>
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

// Q1. Merge Lists Alternatingly.
void mergeList(struct Node **p, struct Node **q)
{
    // Code here
    Node *p1 = (*p);
    Node *q1 = (*q);

    Node *r1 = NULL;
    Node *r2 = NULL;

    while (p1 != NULL && q1 != NULL)
    {
        r1 = p1->next;
        r2 = q1->next;

        p1->next = q1;
        q1->next = r1;

        p1 = r1;
        q1 = r2;
    }

    (*q) = q1;
    return;
}

// Q3. Given a linked list of 0s, 1s and 2s, sort it.
Node *segregate(Node *head)
{

    // Add code here

    if (head->next == NULL)
        return head;

    Node *curr = head;
    Node *head0 = new Node(0);
    Node *tail0 = head0;

    Node *head1 = new Node(1);
    Node *tail1 = head1;

    Node *head2 = new Node(2);
    Node *tail2 = head2;

    while (curr)
    {
        if (curr->data == 0)
        {
            tail0->next = curr;
            tail0 = tail0->next;
            curr = curr->next;
            tail0->next = NULL;
        }
        else if (curr->data == 1)
        {
            tail1->next = curr;
            tail1 = tail1->next;
            curr = curr->next;
            tail1->next = NULL;
        }
        else
        {
            tail2->next = curr;
            tail2 = tail2->next;
            curr = curr->next;
            tail2->next = NULL;
        }
    }

    if (head1->next)
    {
        tail0->next = head1->next;
        tail1->next = head2->next;
    }
    else
    {
        tail0->next = head2->next;
    }

    tail0 = head0;
    head0 = head0->next;
    delete tail0;

    tail1 = head1;
    head1 = head1->next;
    delete tail1;

    tail2 = head2;
    head2 = head2->next;
    delete tail2;

    return head0;
}

int main() {}