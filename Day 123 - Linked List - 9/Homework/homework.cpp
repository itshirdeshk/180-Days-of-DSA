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

// Q1. Reverse a sublist of a linked list.
Node *reverseBetween(Node *head, int m, int n)
{
    // code here
    Node *first = NULL;
    Node *second = head;
    for (int i = 1; i < m; i++)
    {
        first = second;
        second = second->next;
    }

    Node *prev = second;
    Node *curr = second->next;
    Node *fut = NULL;

    for (int i = m; i < n; i++)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }

    if (m != 1)
    {
        first->next = prev;
        second->next = curr;
    }
    else
    {
        second->next = curr;
        head = prev;
    }

    return head;
}

// Q2. Multiply two linked lists.
#define mod 1000000007
long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    long long num1 = 0, num2 = 0;
    Node *temp1 = l1, *temp2 = l2;
    while (temp1)
    {
        num1 = ((num1 * 10) + temp1->data) % mod;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        num2 = ((num2 * 10) + temp2->data) % mod;
        temp2 = temp2->next;
    }

    long long ans = (num1 * num2) % mod;

    return ans;
}

int main() {}