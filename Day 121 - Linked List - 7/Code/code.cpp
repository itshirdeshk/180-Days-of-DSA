#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool check(vector<Node *> &visited, Node *curr)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == curr)
            return 1;
    }
    return 0;
}

// Q1. Detect Loop in linked list.
// Method 1:
bool detectLoop(Node *head)
{
    // your code here
    Node *curr = head;
    vector<Node *> visited;

    while (curr)
    {
        if (check(visited, curr))
            return 1;
        visited.push_back(curr);
        curr = curr->next;
    }
    return 0;
}

// Method 2:
bool detectLoop(Node *head)
{
    // your code here
    Node *curr = head;
    unordered_map<Node *, bool> visited;

    while (curr)
    {
        if (visited[curr] == 1)
            return 1;
        visited[curr] = 1;
        curr = curr->next;
    }
    return 0;
}

// Method 3:
bool detectLoop(Node *head)
{
    // your code here
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}

// Q2. Find length of Loop.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return 0;
    int count = 1;
    slow = slow->next;
    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }

    return count;
}

int main() {}