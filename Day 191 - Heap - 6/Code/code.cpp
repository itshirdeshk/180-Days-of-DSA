#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Q1. Merge K sorted linked lists.
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        // For heap comparision is reverse
        return a->data >= b->data;
    }
};
// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    priority_queue<Node *, vector<Node *>, Compare> p(arr, arr + K);
    Node *root = new Node(0);
    Node *tail = root;

    Node *temp;

    while (!p.empty())
    {
        temp = p.top();
        p.pop();
        tail->next = temp;
        tail = tail->next;

        if (temp->next)
        {
            p.push(temp->next);
        }
    }
    return root->next;
}

// Q2. Merge k Sorted Arrays.
// Method 1:
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < K; i++)
    {
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    vector<int> ans;

    pair<int, pair<int, int>> element;
    int i, j;

    while (!p.empty())
    {
        element = p.top();
        p.pop();
        ans.push_back(element.first);
        i = element.second.first;
        j = element.second.second;

        if (j + 1 < K)
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

// Method 2:
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            index++, right++;
        }
    }

    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }

    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergeSort(vector<int> &arr, int start, int end, int portion, int K)
{
    if (portion < 2)
        return;

    int mid = start + (portion / 2) * K - 1;
    mergeSort(arr, start, mid, portion / 2, K);
    mergeSort(arr, mid + 1, end, portion - portion / 2, K);
    merge(arr, start, mid, end);
}

// Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    vector<int> ans;

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            ans.push_back(arr[i][j]);
        }
    }

    mergeSort(ans, 0, ans.size() - 1, K, K);
    return ans;
}












int main() {}