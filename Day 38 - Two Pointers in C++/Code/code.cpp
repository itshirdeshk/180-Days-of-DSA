#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Segregate 0s and 1s.
void segregate0and1(int arr[], int n)
{
    // code here
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (arr[start] == 0)
            start++;
        else
        {
            if (arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else
                end--;
        }
    }
}

// Q2. Two Sum II - Input Array Is Sorted.
// Approach 1: Using Binary Search
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans(2);
    int ans1, ans2;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        int num = target - numbers[i];
        int start = i + 1, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (numbers[mid] == num)
            {
                ans1 = i;
                ans2 = mid;
                break;
            }
            else if (numbers[mid] < num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    ans[0] = ans1 + 1;
    ans[1] = ans2 + 1;
    return ans;
}

// Approach 2: Using Two Pointers
vector<int> twoSum(vector<int> &numbers, int target)
{
    int ans1, ans2;
    int start = 0, end = numbers.size() - 1;
    while (start < end)
    {
        if (numbers[start] + numbers[end] == target)
        {
            ans1 = start;
            ans2 = end;
            break;
        }
        else if (numbers[start] + numbers[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    vector<int> ans = {ans1 + 1, ans2 + 1};
    return ans;
}

// Q3. Pair With Given Difference
int solve(vector<int> &A, int B)
{
    int n = A.size();
    sort(A.begin(), A.end());

    int start = 0, end = 1;

    if (B < 0)
        B = B * -1;

    while (end < n)
    {
        if (A[end] - A[start] == B)
        {
            return 1;
        }
        else if (A[end] - A[start] < B)
        {
            end++;
        }
        else
        {
            start++;
        }

        if (start == end)
            end++;
    }

    return 0;
}

int main() {}