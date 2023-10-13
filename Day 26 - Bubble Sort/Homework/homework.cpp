#include <iostream>
using namespace std;

int main()
{

    // Q1. Use Bubble Sort Algorithm to sort the array of integers in decreasing order.
    int arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int swapped = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Q2. Bubble Sort Algorithm to sort the array of integers in increasing order by taking the smallest number to first place by starting from the last. Question was explained in the class.
    int arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int swapped = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Q3. Bubble Sort Algorithm to sort the array of char in ascending order.
    char arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int swapped = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}