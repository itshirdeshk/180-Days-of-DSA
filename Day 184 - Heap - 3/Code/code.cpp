#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Height of Heap.
int heapHeight(int N, int arr[])
{
    // code here
    if (N == 1)
        return 1;
    int height = 0;
    while (N > 1)
    {
        height++;
        N /= 2;
    }
    return height;
}

// Q2. Minimum Cost of ropes.
long long minCost(long long arr[], long long n)
{
    // Your code here

    priority_queue<long long, vector<long long>, greater<long long>> p;

    for (long long i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    long long cost = 0;

    while (p.size() > 1)
    {
        long long rope = p.top();
        p.pop();

        rope += p.top();
        p.pop();

        cost += rope;

        p.push(rope);
    }

    return cost;
}

// Q3. Magician and Chocolates.
int nchoc(int A, vector<int> &B)
{
    // max heap
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
        p.push(B[i]);

    long long ans = 0;
    while (A && (!p.empty()))
    {
        ans += p.top();

        if (p.top() / 2)
        {
            p.push(p.top() / 2);
        }
        p.pop();
        A--;
    }
    return ans % 1000000007;
}

// Q4. Last Stone Weight.
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> p;
    for (int i = 0; i < stones.size(); i++)
        p.push(stones[i]);

    while (p.size() > 1)
    {
        int first = p.top();
        p.pop();

        int second = p.top();
        p.pop();

        int destroy = abs(first - second);

        if (destroy != 0)
            p.push(destroy);
        else
        {
            if (p.empty())
                p.push(destroy);
        }
    }
    // return p.empty() ? 0 : p.top();
    return p.top();
}

// Q5. Take Gifts From the Richest Pile.
long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<int> p(gifts.begin(), gifts.end());
    while (k--)
    {
        p.push(floor(sqrt(p.top())));
        p.pop();
    }

    long long sum = 0;
    while (!p.empty())
    {
        sum += p.top();
        p.pop();
    }

    return sum;
}

// Q6. Profit Maximisation.
int solve(vector<int> &A, int B)
{
    int sum = 0;
    priority_queue<int> p;

    for (int i = 0; i < A.size(); i++)
        p.push(A[i]);

    while (B && !(p.empty()))
    {
        sum += p.top();

        if (p.top() - 1)
            p.push(p.top() - 1);
        p.pop();

        B--;
    }
    return sum;
}

int main() {}