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

// Q1. Rotate List.
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    vector<int> ans;
    ListNode *temp = head;
    while (temp)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }
    int count = ans.size();
    k = k % count;
    if (k == 0)
        return head;
    count -= k;

    temp = head;

    while (count < ans.size())
    {
        temp->val = ans[count++];
        temp = temp->next;
    }

    count = 0;

    while (temp)
    {
        temp->val = ans[count++];
        temp = temp->next;
    }

    return head;
}

// Q2. Palindrome Linked List.
bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
        return 1;
    vector<int> ans;
    ListNode *temp = head;
    while (temp)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int start = 0, end = ans.size() - 1;
    while (start < end)
    {
        if (ans[start] != ans[end])
            return 0;
        start++, end--;
    }

    return 1;
}

int main() {}