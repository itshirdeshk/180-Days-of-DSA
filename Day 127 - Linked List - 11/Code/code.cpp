#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *find(Node *curr1, Node *curr2, Node *X)
{
    if (X == NULL)
        return NULL;
    while (curr1 != X)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr2;
}

// Q1.
// Method 1:
Node *copyList(Node *head)
{
    // Write your code here
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created of singly Linked List i.e. without random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Assign random pointer to the clone LL
    tailCopy = headCopy;
    temp = head;

    while (temp)
    {
        tailCopy->arb = find(head, headCopy, temp->arb);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    return headCopy;
}

// Method 2:
Node *copyList(Node *head)
{
    // Write your code here
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created of singly Linked List i.e. without random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Assign random pointer to the clone LL
    tailCopy = headCopy;
    temp = head;

    unordered_map<Node *, Node *> map;

    while (temp)
    {
        map[temp] = tailCopy;
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    tailCopy = headCopy;
    temp = head;

    while (temp)
    {
        tailCopy->arb = map[temp->arb];
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    return headCopy;
}

// Method 3:
Node *copyList(Node *head)
{
    // Write your code here
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    // Clone created of singly Linked List i.e. without random pointer
    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = head;

    // Insert clone LL inbetween the original LL
    Node *curr1 = head, *curr2 = headCopy;
    Node *front1, *front2;

    while (curr1)
    {
        front1 = curr1->next;
        front2 = curr2->next;

        curr1->next = curr2;
        curr2->next = front1;

        curr1 = front1;
        curr2 = front2;
    }

    // Assign random pointers to clone LL
    curr1 = head;
    while (curr1)
    {
        curr2 = curr1->next;
        if (curr1->arb)
            curr2->arb = curr1->arb->next;
        curr1 = curr2->next;
    }

    // Break the LL
    curr1 = head;
    while (curr1->next)
    {
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
    }

    return headCopy;

    return headCopy;
}




int main() {}