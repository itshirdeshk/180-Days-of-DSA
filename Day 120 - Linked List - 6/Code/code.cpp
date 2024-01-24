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

// Q1. Remove duplicate element from sorted Linked List.
// Method 1:
Node *removeDuplicates(Node *head)
{
    // your code goes here
    vector<int> ans;
    ans.push_back(head->data);

    Node *curr = head->next;
    while (curr)
    {
        if (ans[ans.size() - 1] != curr->data)
        {
            ans.push_back(curr->data);
        }
        curr = curr->next;
    }
    curr = head;
    int index = 0;
    Node *prev = NULL;

    while (index < ans.size())
    {
        curr->data = ans[index++];
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    return head;
}

// Method 2:
Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (!head || !head->next)
        return head;

    Node *curr = head->next, *prev = head;
    while (curr)
    {
        if (curr->data == prev->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}

// Q2. Merge two sorted linked lists.
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *head = new Node(0);
    Node *tail = head;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }

    if (head1)
        tail->next = head1;
    else
        tail->next = head2;

    tail = head;
    head = head->next;
    delete tail;
    return head;
}

// Q2. Merge two sorted linked lists.
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *head = new Node(0);
    Node *tail = head;

    Node *tail1 = head1, *tail2 = head2;
    while (tail1 && tail2)
    {
        if (tail1->data <= tail2->data)
        {
            tail->next = new Node(tail1->data);
            tail = tail->next;
            tail1 = tail1->next;
        }
        else
        {
            tail->next = new Node(tail2->data);
            tail = tail->next;
            tail2 = tail2->next;
        }
    }

    if (tail1)
    {
        tail->next = tail1;
    }
    else
    {
        tail->next = tail2;
    }

    tail = head;
    head = head->next;
    delete tail, tail1, tail2;

    return head;
}

// Q3. Given a linked list of 0s, 1s and 2s, sort it.
Node *segregate(Node *head)
{
    // Add code here
    Node *curr = head;
    int count0 = 0, count1 = 0, count2 = 0;

    while (curr)
    {
        if (curr->data == 0)
            count0++;
        else if (curr->data == 1)
            count1++;
        else
            count2++;
        curr = curr->next;
    }

    curr = head;
    while (count0--)
    {
        curr->data = 0;
        curr = curr->next;
    }
    while (count1--)
    {
        curr->data = 1;
        curr = curr->next;
    }
    while (count2--)
    {
        curr->data = 2;
        curr = curr->next;
    }

    return head;
}

int main() {}