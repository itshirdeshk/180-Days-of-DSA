#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

// Q1. Kth element in Matrix.
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Your code here
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));
    }
    // create min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    int ans;
    pair<int, pair<int, int>> element;

    int i, j;

    while (k--)
    {
        element = p.top();
        p.pop();
        ans = element.first;
        i = element.second.first;
        j = element.second.second;

        if (j + 1 < n)
            p.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));
    }

    return ans;
}

// Q2. Find median in a stream.
priority_queue<int> leftMaxHeap;
priority_queue<int, vector<int>, greater<int>> rightMinHeap;
// Function to insert heap.
void insertHeap(int &x)
{
    if (leftMaxHeap.empty())
    {
        leftMaxHeap.push(x);
        return;
    }

    if (x > leftMaxHeap.top())
        rightMinHeap.push(x);
    else
        leftMaxHeap.push(x);

    balanceHeaps();
}

// Function to balance heaps.
void balanceHeaps()
{
    if (rightMinHeap.size() > leftMaxHeap.size())
    {
        leftMaxHeap.push(rightMinHeap.top());
        rightMinHeap.pop();
    }
    else
    {
        if (rightMinHeap.size() < leftMaxHeap.size() - 1)
        {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
    }
}

// Function to return Median.
double getMedian()
{
    if (leftMaxHeap.size() > rightMinHeap.size())
        return leftMaxHeap.top();
    else
    {
        double ans = (leftMaxHeap.top() + rightMinHeap.top()) / 2;
        return ans;
    }
}

int main() {}