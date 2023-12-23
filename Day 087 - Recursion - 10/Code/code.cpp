#include <iostream>
using namespace std;

// Q1. Subset Sum
void print(int arr[], int index, int n, int sum)
{
    if (index == n)
    {
        cout << sum << endl;
        return;
    }
    print(arr, index + 1, n, sum);
    print(arr, index + 1, n, sum + arr[index]);
}

// Q2. Target Sum
bool find(int arr[], int index, int n, int target)
{
    if (target == 0)
        return 1;
    if (index == n || target < 0)
        return 0;

    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main() {}