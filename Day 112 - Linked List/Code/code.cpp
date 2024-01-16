#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *createLL(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLL(arr, index + 1, size);
    return temp;
}

Node *createLL2(int arr[], int index, int size, Node *prev)
{
    if (index == size)
        return prev;
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = prev;
    return createLL2(arr, index + 1, size, temp);
}

// Homework Question: Insert a Node at a particular position by using recursion.
void insertAtPos(Node *&Head, int x, int value, int index)
{
    if (index == x)
    {
        Node *temp = new Node(value);
        temp->next = Head->next;
        Head->next = temp;
        return;
    }

    insertAtPos(Head->next, x, value, index + 1);
}

int main()
{
    // Static way
    Node A1(4);

    // Dynamic way
    Node *Head;
    Node *Tail;
    // Head = new Node(4);
    Head = NULL;
    Tail = NULL;
    // cout << Head->data << endl;
    // cout << Head->next << endl;

    int arr[] = {2, 4, 5, 7, 9};

    // // Insert the node at beginning

    // for (int i = 0; i < 5; i++)
    // {
    //     // Linked List doesn't exist
    //     if (Head == NULL)
    //     {
    //         Head = new Node(arr[i]);
    //     }
    //     // Linked List exist
    //     else
    //     {
    //         Node *temp;
    //         temp = new Node(arr[i]);
    //         temp->next = Head;
    //         Head = temp;
    //     }
    // }

    // // Print the value
    // Node *temp = Head;
    // while(temp != NULL){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }

    // Insert the Node at the end of the Linked List
    for (int i = 0; i < 5; i++)
    {
        // LL doesn't exist
        if (Head == NULL)
        {
            Head = new Node(arr[i]);
            Tail = Head;
        }
        // LL exist
        else
        {
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
        }
    }

    // Print the LL
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // Insert a Node at a particular position
    int x = 3; // Insert posiiton
    int value = 30;

    temp = Head;
    for (int i = 0; i < x - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = new Node(value);
    temp2->next = temp->next;
    temp->next = temp2;

    // Print the LL
    temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout<<endl;

    temp = Head;
    insertAtPos(temp, 4, 32, 1);

    // Print the LL
    temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}