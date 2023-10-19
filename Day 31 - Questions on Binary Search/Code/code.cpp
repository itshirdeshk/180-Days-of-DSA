#include <iostream>
#include <vector>
using namespace std;

// Q1. Find First and Last Position of Element in Sorted Array.
vector<int> searchRange(vector<int> &arr, int target)
{
    int start = 0, end = arr.size() - 1, first = -1, last = -1, mid;

    // Find First
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // Find Last
    start = 0;
    end = arr.size() - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // vector<int> ans(2);
    // ans[0] = first;
    // ans[1] = last;

    vector<int> ans = {first, last};

    return ans;
}

// Q2. Search Insert Position.
int searchInsert(vector<int> &arr, int key)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    while (start <= end)
    {
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}

// Q3.Sqrt(x)
int mySqrt(int x)
{

    if (x < 2)
        return x;

    int start = 0, end = x, ans, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid < x / mid)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

// Q4. Peak Index in a Mountain Array.
int findKthPositive(vector<int> &arr, int k)
{
    int start = 0, end = arr.size(), mid;
    while (start <= end)
    {
        // mid = start + (end - start) / 2;
        mid = end + (start - end) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
}