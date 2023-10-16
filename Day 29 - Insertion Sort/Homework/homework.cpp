#include <iostream>
using namespace std;

int main()
{
    // Q1. Use Insertion Sort Algorithm to sort the array of integers in decreasing order.
    int arr[100];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Q2.  Insertion Sort Algorithm to sort the array of integers in increasing order if we start from the last element of the array. Question was explained in the class.
    int arr[100];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}