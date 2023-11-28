#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Frequencies of Limited Range Array Elements.
void frequencyCount(vector<int> &arr, int N, int P)
{
    // code here
    for (int i = 0; i < N; i++)
        arr[i]--;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] % P < N)
        {
            arr[arr[i] % P] += P;
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < N; i++)
        arr[i] /= P;
}

// Q2. First Missing Positive.
int firstMissingPositive(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != j + 1)
        {
            return j + 1;
        }
    }
    return nums.size() + 1;
}

int main() {}