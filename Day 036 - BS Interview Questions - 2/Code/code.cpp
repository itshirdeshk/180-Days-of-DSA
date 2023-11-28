#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Aggressive Cows.
int solve(int n, int k, vector<int> &stalls)
{

    // Write your code here
    int start = 1, end, mid, ans;
    sort(stalls.begin(), stalls.end());
    end = stalls[n - 1] - stalls[0];

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int count = 1, pos = stalls[0];

        for (int i = 1; i < n; i++)
        {
            if (pos + mid <= stalls[i])
            {
                count++;
                pos = stalls[i];
            }
        }

        if (count < k)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    return ans;
}

// Q2. Koko Eating Bananas.
int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 0, end = 0, mid, ans, n = piles.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += piles[i];
        end = max(end, piles[i]);
    }

    start = sum / h;

    if (!start)
    {
        start = 1;
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int total_time = 0;
        for (int i = 0; i < n; i++)
        {
            total_time += piles[i] / mid;
            if (piles[i] % mid)
                total_time++;
        }

        if (total_time > h)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main() {}