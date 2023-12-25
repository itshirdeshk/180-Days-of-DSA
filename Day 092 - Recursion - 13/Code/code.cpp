#include <iostream>
#include <vector>
using namespace std;

// Q1. Permutation - 2.
void permut(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    vector<bool> use(21, 0);
    for (int i = index; i < arr.size(); i++)
    {
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[index], arr[i]);
            permut(arr, ans, index + 1);
            swap(arr[index], arr[i]);
            use[arr[i] + 10] = 1;
        }
    }
}

// Q2. Ways to sum to N.
int way(int arr[], int m, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += way(arr, m, sum - arr[i]);
    }

    return ans % 1000000007;
}

int main() {}