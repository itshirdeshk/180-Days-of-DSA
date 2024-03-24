#include <iostream>
#include <vector>
using namespace std;

// Q1. Trapping Rain Water.
int trap(vector<int> &height)
{

    int n = height.size();
    int leftmax = 0, rightmax = 0, maxheight = height[0], index = 0, water = 0;

    // Max height of building
    for (int i = 1; i < n; i++)
    {
        if (maxheight < height[i])
        {
            maxheight = height[i];
            index = i;
        }
    }

    // Left Part
    for (int i = 0; i < index; i++)
    {
        if (leftmax > height[i])
        {
            water += leftmax - height[i];
        }
        else
        {
            leftmax = height[i];
        }
    }

    // Right Part
    for (int i = n - 1; i > index; i--)
    {
        if (rightmax > height[i])
        {
            water += rightmax - height[i];
        }
        else
        {
            rightmax = height[i];
        }
    }

    return water;
}

// Q2. Three Sum.
bool find3Numbers(int A[], int n, int X)
{
    // Your Code Here
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }

    for (int i = 0; i < n - 2; i++)
    {
        int ans = X - A[i];
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            if (A[start] + A[end] == ans)
            {
                return 1;
            }
            else if (A[start] + A[end] > ans)
                end--;
            else
                start++;
        }
    }
    return 0;
}

int main() {}