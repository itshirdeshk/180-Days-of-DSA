#include <iostream>
using namespace std;

// Q1. Print Array.
// First Approach
void print(int arr[], int index, int n)
{
    if (index == n)
        return;
    cout << arr[index] << " ";
    print(arr, index + 1, n);
}

// Second Approach
void print2(int arr[], int index)
{
    if (index == -1)
        return;
    cout << arr[index] << " ";
    print2(arr, index - 1);
}

// Q2. Sum of all elements
int sum(int arr[], int index, int n)
{
    if (index == n)
        return 0;
    return arr[index] + sum(arr, index + 1, n);
}

// Q3. Min Element
int minElement(int arr[], int index, int n)
{
    if (index == n - 1)
        return arr[index];

    return min(arr[index], minElement(arr, index + 1, n));
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7};
}