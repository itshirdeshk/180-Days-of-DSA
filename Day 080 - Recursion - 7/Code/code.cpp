#include <iostream>
using namespace std;

// Q1. Linear Search.
bool linearSearch(int arr[], int X, int index, int N)
{
    if (index == N)
        return 0;

    if (arr[index] == X)
        return 1;

    return linearSearch(arr, X, index + 1, N);
}

// Q2. Binary Search.
bool binarySearch(int arr[], int start, int end, int X)
{
    if (start > end)
        return 0;

    int mid = start + (end - start) / 2;

    if (arr[mid] == X)
        return 1;
    else if (arr[mid] > X)
        return binarySearch(arr, mid + 1, end, X);
    else
        return binarySearch(arr, start, mid - 1, X);
}

int main() {}