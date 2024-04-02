#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Kth smallest element.
int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    //  max heap
    priority_queue<int> p;
    for (int i = 0; i < k; i++)
        p.push(arr[i]);

    for (int i = k; i <= r; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

// Q2. Kth Largest Element in an Array.
int findKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < k; i++)
        p.push(arr[i]);

    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

// Q3. Kth largest element in a stream.
// (Homework Question)
vector<int> kthLargest(int k, int arr[], int n)
{
    // code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
        if (p.size() < k)
            ans.push_back(-1);
        else
        {
            if (p.size() > k)
                p.pop();
            ans.push_back(p.top());
        }
    }

    return ans;
}

// Q4. Sum of elements between k1'th and k2'th smallest elements.
long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
{
    // Your code goes here

    // max heap
    priority_queue<long long> p1;
    priority_queue<long long> p2;

    for (long long i = 0; i < K1; i++)
        p1.push(A[i]);
    for (long long i = 0; i < K2 - 1; i++)
        p2.push(A[i]);

    // find k1 smallest element in the array
    for (long long i = K1; i < N; i++)
    {
        if (A[i] < p1.top())
        {
            p1.pop();
            p1.push(A[i]);
        }
    }
    // find k2 - 1 smallest element in the array
    for (long long i = K2 - 1; i < N; i++)
    {
        if (A[i] < p2.top())
        {
            p2.pop();
            p2.push(A[i]);
        }
    }

    long long sum1 = 0;
    long long sum2 = 0;

    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}

int main() {}