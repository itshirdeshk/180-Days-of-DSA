#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Subarray Sums Divisible by K.
int subarraysDivByK(vector<int> &nums, int k)
{
    // Unordered Map
    unordered_map<int, int> m;
    m[0] = 1;

    int prefixSum = 0, rem, total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        rem = prefixSum % k;

        if (rem < 0)
            rem = k + rem;

        if (m.count(rem))
        {
            total += m[rem];
            m[rem]++;
        }
        else
        {
            m[rem] = 1;
        }
    }
    return total;
}

// Q2. Subarray Product Less Than K.
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int product = 1, start = 0, end = 0, n = nums.size(), count = 0;

    while (end < n)
    {
        product *= nums[end];
        while (product >= k && start <= end)
        {
            product /= nums[start++];
        }

        count += end - start + 1;
        end++;
    }

    return count;
}

int main() {}