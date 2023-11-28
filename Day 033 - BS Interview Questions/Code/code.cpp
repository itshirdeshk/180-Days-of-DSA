#include <iostream>
using namespace std;

// Q1. Allocate minimum number of pages.
int findPages(int A[], int N, int M)
{
    // code here
    if (M > N)
        return -1;

    int start = 0, end = 0, ans, mid;
    for (int i = 0; i < N; i++)
    {
        start = max(start, A[i]);
        end += A[i];
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int pages = 0, count = 1;

        for (int i = 0; i < N; i++)
        {
            pages += A[i];
            if (pages > mid)
            {
                count++;
                pages = A[i];
            }
        }

        if (count <= M)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

// Q2. The Painter's Partition Problem.
long long minTime(int A[], int N, int M)
{
    // code here
    // return minimum time

    long long start = 0, end = 0, ans, mid;
    for (int i = 0; i < N; i++)
    {
        if (start < A[i])
            start = A[i];
        end += A[i];
    }

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        long long pages = 0, count = 1;

        for (int i = 0; i < N; i++)
        {
            pages += A[i];
            if (pages > mid)
            {
                count++;
                pages = A[i];
            }
        }

        if (count <= M)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
}