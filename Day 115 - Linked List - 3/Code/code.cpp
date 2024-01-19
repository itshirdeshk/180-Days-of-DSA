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

// Q1. Reverse Linked List.
// Method 1:
ListNode *reverseList(ListNode *head)
{
    vector<int> ans;
    ListNode *temp = head;

    while (temp != NULL)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int i = ans.size() - 1;
    temp = head;
    while (temp)
    {
        temp->val = ans[i];
        i--;
        temp = temp->next;
    }

    return head;
}

// Method 2:
ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head, *prev = NULL, *fut = NULL;
    while (curr)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    head = prev;
    return head;
}

// Method 3:
// By using recursion:
ListNode *reverse(ListNode *curr, ListNode *prev)
{
    if (curr == NULL)
        return prev;

    ListNode *fut = curr->next;
    curr->next = prev;
    return reverse(fut, curr);
}

// Q2. Middle of the Linked List.
// Method 1:
ListNode *middleNode(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;
    temp = head;

    while (count--)
    {
        temp = temp->next;
    }

    return temp;
}

// Method 2:
// By using slow and fast pointers concept:
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {}