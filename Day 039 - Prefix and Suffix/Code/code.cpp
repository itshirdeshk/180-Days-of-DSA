#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// Q1. Divide array in 2 subarray with equal sum.
bool divide(vector<int> arr)
{
    int prefix = 0, total_sum = 0, n = arr.size();

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        prefix += arr[i];
        // int ans = total_sum - prefix;
        if (total_sum == 2 * prefix)
            return 1;
    }

    return 0;
}

// Q2. Largest Sum Contagious Array (Kadane's Algo).
long long maxSubarraySum(int arr[], int n)
{

    // Your code here
    long long maxi = INT_MIN, prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        maxi = max(maxi, prefix);
        if (prefix < 0)
            prefix = 0;
    }

    return maxi;
}

// Q3. Max Difference between 2 Element.
int maxSubarrayDiff(int arr[], int n)
{
    int max = INT_MIN, suffix = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int diff = suffix - arr[i];
        if (diff > max)
        {
            max = diff;
        }
        if (arr[i] > suffix)
        {
            suffix = arr[i];
        }
    }

    return max;
}

int main()
{
    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxSubarrayDiff(arr, n);
}
