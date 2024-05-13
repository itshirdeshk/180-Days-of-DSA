#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Length of Longest Subarray With at Most K Frequency.
int maxSubarrayLength(vector<int> &nums, int k)
{
    unordered_map<int, int> count;
    int start = 0, end = 0, len = 0;
    while (end < nums.size())
    {
        count[nums[end]]++;
        while (count[nums[end]] > k)
        {
            count[nums[start++]]--;
        }

        len = max(len, end - start + 1);
        end++;
    }
    return len;
}

// Q2. Count Subarrays Where Max Element Appears at Least K Times.
long long countSubarrays(vector<int> &nums, int k)
{
    int start = 0, end = 0, maxEle = INT_MIN, count = 0;
    long long total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        maxEle = max(maxEle, nums[i]);
    }

    while (end < nums.size())
    {
        if (nums[end] == maxEle)
            count++;

        while (count == k)
        {
            total += nums.size() - end;
            if (nums[start] == maxEle)
                count--;
            start++;
        }
        end++;
    }
    return total;
}

// Q3. Subarrays with K Different Integers.
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int total = 0;

    // Atleast(k) - Atleast(k + 1)
    unordered_map<int, int> freq;

    int start = 0, end = 0, n = nums.size(), count = 0;
    while (end < n)
    {
        // freq[nums[end]]++;
        if (++(freq[nums[end]]) == 1)
            count++;

        while (count == k)
        {
            total += n - end;
            freq[nums[start]]--;
            if (freq[nums[start]] == 0)
                count--;

            start++;
        }
        end++;
    }

    start = 0, end = 0, count = 0;
    freq.clear();
    k++;

    while (end < n)
    {
        // freq[nums[end]]++;
        if (++(freq[nums[end]]) == 1)
            count++;

        while (count == k)
        {
            total -= n - end;
            freq[nums[start]]--;
            if (freq[nums[start]] == 0)
                count--;

            start++;
        }
        end++;
    }
    return total;
}

int main() {}