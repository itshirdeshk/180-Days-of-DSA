#include <iostream>
#include<vector>
using namespace std;

// Q1. Subset with sum divisible by m.
int find(vector<int> arr, int index, int n, int sum, int m)
{
    if (sum > 0 && sum % m == 0)
        return 1;
    if (index == n)
        return 0;

    return find(arr, index + 1, n, sum, m) || find(arr, index + 1, n, sum + arr[index], m);
}

int main() {}