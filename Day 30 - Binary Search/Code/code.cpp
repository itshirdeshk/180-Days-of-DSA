#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements in sorted order : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;

    cout << "Enter the element you want to search : ";
    cin >> key;

    cout << binarySearch(arr, n, key);
    return 0;
}