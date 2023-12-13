#include <iostream>
using namespace std;

// Q1. Given an array in non-increasing order, an element is given X, find if that element is present in the array or not. print 1 if its present else print 0.
bool binarySearch(int arr[], int start, int end, int X)
{
    if (start > end)
        return 0;

    int mid = start + (end - start) / 2;

    if (arr[mid] == X)
        return 1;
    else if (arr[mid] > X)
        return binarySearch(arr, start, mid - 1, X);
    else
        return binarySearch(arr, mid + 1, end, X);
}

// Q2. Write a recursive function to reverse the elements of an array.
void reverse(int *arr[], int start, int end)
{
    if (start >= end)
        return;

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

// Q3. Write a recursive function to rotate elements in an array to the right by 1 position.
void rotate(int arr[], int index, int lastNum){
    if(index == 0){
        arr[index] = lastNum;
        return;
    }

    arr[index + 1] = arr[index];
    rotate(arr, index - 1, lastNum);
}

int main() {}