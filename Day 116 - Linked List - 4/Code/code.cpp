#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// Q1. Remove Nth Node From End of List.
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count -= n;
    if (count == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}

// Q2. Remove every kth Node.
Node *deleteK(Node *head, int k)
{
    // Your code here
    Node *curr = head, *prev = NULL;
    if (k == 1)
        return NULL;
    int count = 1;
    while (curr)
    {
        if (k == count)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        }
        else
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return head;
}

// Q3. Rotate List.
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Count the  number of nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    };

    k = k % count;
    if (k == 0)
        return head;
    count -= k;

    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    ListNode *tail = curr;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = head;
    head = curr;

    return head;
}

// Q4. Palindrome Linked List.
bool isPalindrome(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return 1;

    // Count the number of Nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;

    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    ListNode *front = NULL;
    prev = NULL;

    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    ListNode *head1 = head, *head2 = prev;
    while (head1)
    {
        if (head1->val != head2->val)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }

    return 1;
}

int main() {}