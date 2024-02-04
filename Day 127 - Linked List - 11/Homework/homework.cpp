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

void printList(Node *n)
{
    while (n)
    {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int length(Node *n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n = n->next;
    }
    return ret;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next; // storing next node
        current->next = prev; // linking current node to previous
        prev = current;       // updating prev
        current = next;       // updating current
    }
    return prev;
}

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

// Q2.
Node *subLinkedList(Node *l1, Node *l2)
{
    while (l1 != NULL && l1->data == 0)
    {
        l1 = l1->next;
        // removing trailing zeroes from l1
    }
    while (l2 != NULL && l2->data == 0)
    {
        l2 = l2->next;
        // removing trailing zeroes from l2
    }
    int n1 = length(l1);
    int n2 = length(l2);
    if (n1 == 0 && n2 == 0)
    {
        return new Node(0);
    }
    if (n2 > n1)
    {
        std::swap(l1, l2);
        // making sure l1 list has the bigger number
    }
    if (n1 == n2)
    {
        Node *t1 = l1;
        Node *t2 = l2;
        while (t1->data == t2->data)
        {
            // finding which number is greater
            t1 = t1->next;
            t2 = t2->next;
            if (t1 == NULL)
            {
                return new Node(0);
                // returning zero if both numbers are same
            }
        }
        if (t2->data > t1->data)
        {
            std::swap(l1, l2);
            // making sure l1 list has the bigger number
        }
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node *res = NULL;
    Node *t1 = l1;
    Node *t2 = l2;
    while (t1 != NULL)
    {
        int small = 0;
        if (t2 != NULL)
        {
            small = t2->data;
            // 'small' holds the next digit of number to be subtracted
        }
        if (t1->data < small)
        {
            t1->next->data -= 1;
            t1->data += 10;
            // taking carry
        }
        Node *n = new Node(t1->data - small);
        // creating new node for storing difference
        n->next = res;
        res = n;
        t1 = t1->next;
        if (t2 != NULL)
        {
            t2 = t2->next;
        }
    }
    while (res->next != NULL && res->data == 0)
    {
        res = res->next;
        // removing trailing zeroes from result list
    }
    return res;
}

int main() {}