#include <iostream>
#include <vector>
using namespace std;

// Q1. Count Subarrays With Score Less Than K
long long countSubarrays(vector<int> &nums, long long k)
{
    long long product = 1, sum = 0, count = 0, start = 0, end = 0;
    while (end < nums.size())
    {
        sum += nums[end];
        product = sum * (end - start + 1);

        while (product >= k && start <= end)
        {
            sum -= nums[start++];
            product = sum * (end - start + 1);
        }

        count += end - start + 1;
        end++;
    }

    return count;
}

int main() {}