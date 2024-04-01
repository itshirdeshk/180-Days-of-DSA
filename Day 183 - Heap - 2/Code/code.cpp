#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    // Step Down
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void sortArray(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    BuildMaxHeap(arr, 10);

    printHeap(arr, 10);

    sortArray(arr, 10);

    printHeap(arr, 10);

    // Priority Queue
    priority_queue<int> p; // Max Heap
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(50);

    cout << p.top() << " ";

    // Delete
    p.pop();
    cout << p.top() << " ";

    // Size
    cout << p.size() << endl;

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }

    priority_queue<int, vector<int>, greater<int>> p; // Min Heap

    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(50);

    cout << p.top() << " ";

    // Delete
    p.pop();
    cout << p.top() << " ";

    // Size
    cout << p.size() << endl;

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}




