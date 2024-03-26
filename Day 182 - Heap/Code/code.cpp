#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;
    int totalSize;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }

    // Insert into the Heap
    void insert(int value)
    {
        // if heap size is available or not
        if (size == totalSize)
        {
            cout << "Heap Overflow \n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // Compare it with its parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " inserted into the heap" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " deleted from the Heap!\n";
        arr[0] = arr[size - 1];
        size--;

        if (size == 0)
            return;

        heapify(0);
    }
};

int main()
{
    MaxHeap h1(6);
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);

    h1.print();

    h1.insert(134);
    h1.insert(142);
    h1.insert(156);

    h1.print();

    h1.Delete();
    h1.print();

    h1.Delete();
    h1.print();
}