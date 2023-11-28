#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Q1. Maximum prefix sum for a given range.
vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q)
{
    vector<int> ans(Q);

    for (int i = 0; i < Q; i++)
    {
        int prefix = 0, maxi = INT_MIN;
        for (int j = L[i]; j <= R[i]; j++)
        {
            prefix += a[j];
            maxi = max(maxi, prefix);
            // if(prefix < 0)
            //     prefix = 0;
        }

        ans[i] = maxi;
    }

    return ans;
}

// Q2. 

int main() {}