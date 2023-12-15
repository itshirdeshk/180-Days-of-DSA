#include <iostream>
#include <vector>
using namespace std;

void mergeDesc(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[right];
            index++, right++;
        }
        else
        {
            temp[index] = arr[left];
            index++, left++;
        }
    }

    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }

    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
}

// Q1. Sort an array in non-increasing order using Merge Sort.
void mergeSortDesc(int arr[], int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    mergeSortDesc(arr, start, mid);
    mergeSortDesc(arr, mid + 1, end);
    mergeDesc(arr, start, mid, end);
}

long long count = 0;

void merge(long long arr[], long long start, long long mid, long long end)
{
    vector<long long> temp(end - start + 1);

    long long left = start, right = mid + 1, index = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index++] = arr[left++];
        }
        else
        {
            count += (mid - left + 1);
            temp[index++] = arr[right++];
        }
    }

    while (left <= mid)
        temp[index++] = arr[left++];
    while (right <= end)
        temp[index++] = arr[right++];

    index = 0;
    while (start <= end)
    {
        arr[start++] = temp[index++];
    }
}

void mergeSort(long long arr[], long long start, long long end)
{
    if (start == end)
        return;

    long long mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// Q2. Count Inversions.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    mergeSort(arr, 0, N - 1);
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 9};
    mergeSortDesc(arr, 0, 6);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}