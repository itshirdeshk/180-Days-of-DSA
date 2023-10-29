#include <iostream>
#include <vector>
using namespace std;

// Q1. Find Peak Element.
int findPeakElement(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1, mid;
    int n = arr.size();
    if (arr.size() < 2)
        return 0;

    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    while (start <= end)
    {
        mid = end + (start - end) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// Q2. Special Array With X Elements Greater Than or Equal X.


// Q3.Valid Perfect Square.
bool isPerfectSquare(int num)
{
    if (num == 1)
        return 1;
    int start = 1, end = num, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid == num / mid)
        {
            if (mid * mid == num)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (mid > num / mid)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return 0;
}



int main()
{
    cout << isPerfectSquare(5);
}