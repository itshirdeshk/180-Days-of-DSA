#include <iostream>
using namespace std;

int main()
{
    // Q1. Use a Selection Sort Algorithm to sort the array of integers in decreasing order.
    int arr[1000];
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;

    cout<<"Enter the elements : ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    for(int i = 0; i < n - 1; i++){
        int index = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[index]) {
                index = j;
            }
        }

        swap(arr[i], arr[index]);
    }

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    // Q2. Use a Selection Sort Algorithm to sort the array of integers in increasing order by taking the highest number to last place.
    int arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }

        swap(arr[i], arr[index]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Q3. Use a Selection Sort Algorithm to sort the array of char in ascending order.

    char arr[1000];
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }

        swap(arr[i], arr[index]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}