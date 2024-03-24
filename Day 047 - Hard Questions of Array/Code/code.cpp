#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Find Missing And Repeating.
vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    vector<int> ans(2);
    for (int i = 0; i < n; i++)
        arr[i]--;

    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % n == 2)
            ans[0] = i + 1;
        else if (arr[i] / n == 0)
            ans[1] = i + 1;
    }

    return ans;
}

// Q2. Majority Element.
int majorityElement(int arr[], int n)
{

    // your code here
    int candidate, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            candidate = arr[i];
        }

        else
        {
            if (candidate == arr[i])
                count++;
            else
                count--;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == candidate)
            count++;

    if (count > n / 2)
        return candidate;
    else
        return -1;
}

int main() {}