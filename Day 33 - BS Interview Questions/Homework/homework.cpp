#include <iostream>
#include<vector>
using namespace std;

// Q1. Capacity To Ship Packages Within D Days.
int shipWithinDays(vector<int> &A, int M)
{
    int start = 0, end = 0, ans, mid;
    int N = A.size();
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

int main() {}