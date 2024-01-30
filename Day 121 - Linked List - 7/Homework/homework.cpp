#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Q1. Circular Linked List Traversal.
void printList(struct Node *head)
{
    // code here
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Q2. Check If Circular Linked List.
bool isCircular(Node *head)
{
    // Your code here
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        if (temp == head)
            return 1;
    }
    return 0;
}

// Q3. 


int main() {}