#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

// Q1.  Sliding Window Maximum.
// Method 1:
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i <= n - k; i++)
    {
        int total = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            total = max(total, nums[j]);
        }
        ans.push_back(total);
    }
    return ans;
}

// Method 2:
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> d;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < k - 1; i++)
    {
        if (d.empty())
            d.push_back(i);
        else
        {
            while (!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();
            d.push_back(i);
        }
    }

    for (int i = k - 1; i < n; i++)
    {
        while (!d.empty() && nums[i] > nums[d.back()])
            d.pop_back();
        d.push_back(i);
        if (d.front() <= i - k)
            d.pop_front();
        ans.push_back(nums[d.front()]);
    }
    return ans;
}

// Q2. Minimum Number of K Consecutive Bit Flips.
// Method 1:
int minKBitFlips(vector<int> &nums, int k)
{
    int flip = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            if (i + k - 1 >= n)
                return -1;
            for (int j = i; j <= i + k - 1; j++)
                nums[j] = !nums[j];
            flip++;
        }
    }
    return flip;
}

// Method 2:
int minKBitFlips(vector<int> &nums, int k)
{
    int flip = 0;
    int n = nums.size();
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!q.empty() && q.front() < i)
            q.pop();
        if (q.size() % 2 == nums[i])
        {
            if (i + k - 1 >= n)
                return -1;
            q.push(i + k - 1);
            flip++;
        }
    }
    return flip;
}

int main() {}