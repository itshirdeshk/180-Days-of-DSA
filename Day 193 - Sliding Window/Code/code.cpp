#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Zero Sum Subarrays.
long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    long long int total = 0;

    unordered_map<long long int, long long int> m;
    long long int prefixSum = 0;

    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (m.count(prefixSum))
        {
            total += m[prefixSum];
            m[prefixSum]++;
        }
        else
        {
            m[prefixSum] = 1;
        }
    }

    return total;
}

// Q2. Subarray Sum Equals K
int subarraySum(vector<int> &arr, int k)
{
    unordered_map<int, int> m;
    m[0] = 1;
    int prefixSum = 0, total = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        if (m.count(prefixSum - k))
        {
            total += m[prefixSum - k];
            m[prefixSum]++;
        }
        else
        {
            m[prefixSum]++;
        }
    }

    return total;
}

int main() {}