#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pos = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] >= arr[end])
        {
            swap(arr[pos], arr[i]);
            pos++;
        }
    }
    return pos - 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot, end);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quickSort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
}