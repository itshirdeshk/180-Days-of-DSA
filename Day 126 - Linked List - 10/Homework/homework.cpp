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

struct Node
{
    int data;
    struct Node *next, *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node *merge(Node *firstNode, Node *secondNode)
{
    Node *merged = new Node(-1);
    Node *temp = new Node(-1);
    // merged is equal to temp so in the end we have the top
    // Node.
    merged = temp;
    // while either firstNode or secondNode becomes NULL
    while (firstNode != NULL && secondNode != NULL)
    {
        if (firstNode->data <= secondNode->data)
        {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else
        {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    // any remaining Node in firstNode or secondNode gets
    // inserted in the temp List
    while (firstNode != NULL)
    {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
    while (secondNode != NULL)
    {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    // return the head of the sorted list
    return merged->next;
}
// function to calculate the middle Element
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (!slow->next && (!fast && !fast->next))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merge(struct Node *first, struct Node *second)
{
    // base cases when either of two halves is null.
    if (!first)
        return second;
    if (!second)
        return first;
    // comparing data in both halves and storing the smaller in result and
    // recursively calling the merge function for next node in result.
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        // returning the resultant list.
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        // returning the resultant list.
        return second;
    }
}
// Function to split the list into two halves.
struct Node *splitList(struct Node *head)
{
    // using two pointers to find the midpoint of list
    struct Node *fast = head, *slow = head;
    // first pointer, slow moves 1 node and second pointer, fast moves
    // 2 nodes in one iteration.
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow is before the midpoint in the list, so we split the
    // list in two halves from that point.
    struct Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Q1. Merge Sort for Linked List.
Node *mergeSort(Node *head)
{
    // your code here
    if (head->next == NULL)
    {
        return head;
    }
    Node *mid = new Node(-1);
    Node *head2 = new Node(-1);
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL;
    Node *finalhead = merge(mergeSort(head), mergeSort(head2));
    return finalhead;
};

// Q2. Merge Sort on Doubly Linked List.
struct Node *sortDoubly(struct Node *head)
{
    if (!head || !head->next)
        return head;
    // splitting the list into two halves.
    struct Node *second = splitList(head);
    // calling the sortDoubly function recursively for both parts separately.
    head = sortDoubly(head);
    second = sortDoubly(second);
    // calling the function to merge both halves.
    return merge(head, second);
}

// Q3. Reorder List.
void reorderList(struct Node *head)
{
    int r = 0, c;
    struct Node *temp, *temp1, *temp2, *p;
    temp = head;
    // if list contains 2 or lesser nodes, no change needed
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    while (temp != NULL)
    {
        // finding number of nodes in list
        r++;
        temp = temp->next;
    }
    c = (r + 1) / 2;
    // c represents mid point
    temp = head;
    while (c--)
    {
        p = temp;
        temp = temp->next;
    }
    p->next = NULL;
    // dividing the list into 2
    // temp holds the address to head of second half
    temp1 = NULL;
    temp2 = temp;
    // reversing the second half
    while (temp2 != NULL)
    {
        p = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = p;
    }
    // second half is now reversed
    p = temp1;
    // merging the 2 halves by selecting nodes alternatively
    Node *a, *b;
    while (p)
    {
        a = head->next;
        b = p->next;
        head->next = p;
        p->next = a;
        head = a;
        p = b;
    }
}

int main() {}