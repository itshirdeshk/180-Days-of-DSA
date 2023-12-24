#include <iostream>
#include <vector>
using namespace std;

// Q1. Given an array of size N, Print subset sum and corresponding to it, print the given subset also.
void subseqSum(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp, vector<int> &sumArr, int sum)

{
    if (index == n)
    {
        ans.push_back(temp);
        sumArr.push_back(sum);
        return;
    }
    temp.push_back(arr[index]);
    subseqSum(arr, index + 1, n, ans, temp, sumArr, sum);
    temp.pop_back();
    subseqSum(arr, index + 1, n, ans, temp, sumArr, sum + arr[index]);
}

// Q2. Perfect Sum
int subset(int arr[], int index, int sum, int n)
{
    if (index == n)
        return sum == 0;

    return subset(arr, index + 1, sum, n) + subset(arr, index + 1, sum - arr[index], n);
}

int main() {}