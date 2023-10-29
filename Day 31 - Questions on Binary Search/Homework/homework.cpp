#include <iostream>
using namespace std;

// Q1. Count the Zeros.
int countZeroes(int arr[], int n)
{
    // code here
    int start = 0, end = n - 1, count = 0;
    while (arr[start])
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == 1)
        {
            start = mid + 1;
        }
        else
        {
            start++;
        }
    }

    return end - start + 1;
}

// Q2. Number of occurrence.
// Brute Force Approach
int count(int arr[], int n, int x)
{
    // code here
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }

    return count;
}

// Optimized Approach using Binary Search
int count(int arr[], int n, int x)
{
    // code here
    int start = 0, end = n - 1, mid;
    while (arr[start] != x || arr[end] != x)
    {
        if (start <= end)
        {
            mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                if (arr[start] != x)
                {
                    start++;
                }
                if (arr[end] != x)
                {
                    end--;
                }
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            return 0;
        }
    }

    return end - start + 1;
}

// Q3. Cube root of a number.
int cubeRoot(int N)
{
    // code here
    int start = 1, end = N, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid == N / (mid * mid))
        {
            return mid;
        }
        else if (mid > N / (mid * mid))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start - 1;
}

int main() {}