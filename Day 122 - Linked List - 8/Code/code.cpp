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

// Q1. Remove loop in Linked List.
// Method 1:
void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
}

// Method 2:
void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

    int count = 1;
    slow = slow->next;

    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }

    slow = head, fast = head;
    while (count--)
    {
        fast = fast->next;
    }

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
}

// Q2. Intersection Point in Y Shaped Linked Lists.
// Method 1:
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *curr1 = head1, *curr2 = head2;
    int count1 = 0, count2 = 0;

    while (curr1)
    {
        count1++;
        curr1 = curr1->next;
    }

    while (curr2)
    {
        count2++;
        curr2 = curr2->next;
    }

    curr1 = head1, curr2 = head2;

    while (count1 > count2)
    {
        curr1 = curr1->next;
        count1--;
    }
    while (count2 > count1)
    {
        curr2 = curr2->next;
        count2--;
    }

    while (curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if (!curr1)
        return -1;

    return curr1->data;
}

// Method 2:
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *curr1 = head1;
    while (curr1->next)
    {
        curr1 = curr1->next;
    }

    curr1->next = head1;

    Node *slow = head2, *fast = head2;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return -1;

    slow = head2;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

int main() {}