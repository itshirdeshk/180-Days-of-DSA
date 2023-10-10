#include <iostream>
using namespace std;

// Q1. Smallest Positive missing number.

// Q2. Move all negative elements to end.
void segregateElements(int arr[], int n)
{
    // Your code goes here
    int newArr[n];
    int loc = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            newArr[loc] = arr[i];
            loc++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            newArr[loc] = arr[i];
            loc++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
}

// Q3. Number of occurrence.
int count(int arr[], int n, int x)
{
    // code here
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }

    return count;
}

// Q4. Count number of elements between two given elements in array.
int getCount(int arr[], int n, int num1, int num2)
{
    // Complete the function

    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1 && x == -1)
            x = i;
        if (arr[i] == num2)
            y = i;
    }

    if (x == y)
        return 0;

    return (y - x) - 1;
}

// Q5. 

// Q6. 

int main()
{
}