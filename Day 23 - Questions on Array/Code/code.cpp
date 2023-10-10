#include <iostream>
using namespace std;

int search(int arr[], int N, int X)
{

    // Your code here
    for (int i = 0; i <= N; i++)
    {
        if (arr[i] == X)
        {
            return i;
        }
    }
    return -1;
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void fun(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    // Q1. Search Element
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the Element you want to search : ";
    int x;
    cin >> x;

    int ans = search(arr, size, x);
    cout << ans;

    // Q2. Reverse Array
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << "After Swaping : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    // Q3. Second Max
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int max1 = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == max)
        {
            continue;
        }
        else if (arr[i] > max1)
        {
            max1 = arr[i];
        }
    }

    cout << max1 << endl;

    // Q4. Missing Number
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        sum += arr[i];
    }

    sum = size * (size + 1) / 2 - sum;

    cout << sum;

    // Q5. Fibonacci Series
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int arr[num - 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[num - 1];

    // Q6. Cycle Rotate
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cin >> arr[i];
    }

    int temp = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[0] = temp;

    // Array in Functions
    int arr[5] = {1, 2, 3, 4, 5};
    fun(arr, 5);
}