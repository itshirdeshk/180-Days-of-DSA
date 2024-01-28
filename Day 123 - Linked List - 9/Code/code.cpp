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

Node *reverse(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;
    Node *front = curr->next;
    curr->next = prev;
    return reverse(front, curr);
}

// Q1. Add two numbers represented by linked lists.
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    first = reverse(first, NULL);
    second = reverse(second, NULL);

    Node *curr1 = first, *curr2 = second;
    Node *head = new Node(0);
    Node *tail = head;
    int sum = 0, carry = 0;

    // Addition
    while (curr1 && curr2)
    {
        sum = curr1->data + curr2->data + carry;
        tail->next = new Node(sum % 10);
        curr1 = curr1->next;
        curr2 = curr2->next;
        tail = tail->next;
        carry = sum / 10;
    }

    while (curr1)
    {
        sum = curr1->data + carry;
        tail->next = new Node(sum % 10);
        curr1 = curr1->next;
        tail = tail->next;
        carry = sum / 10;
    }

    while (curr2)
    {
        sum = curr2->data + carry;
        tail->next = new Node(sum % 10);
        curr2 = curr2->next;
        tail = tail->next;
        carry = sum / 10;
    }

    while (carry)
    {
        tail->next = new Node(carry % 10);
        carry /= 10;
    }

    head = reverse(head->next, NULL);
    return head;
}

// Q2. Reverse a Linked List in groups of given size.
struct Node *reverseIt(struct Node *head, int k)
{
    // Complete this method
    // First, dummy Node create karo

    Node *first = new Node(0);
    first->next = head;
    head = first;
    int x;
    Node *second, *prev, *curr, *front;

    while (first->next)
    {
        x = k;
        second = first->next;
        prev = first;
        curr = first->next;

        while (x && curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }

        first->next = prev;
        second->next = curr;
        first = second;
    }

    first = head;
    head = head->next;
    delete first;
    return head;
}


int main() {}