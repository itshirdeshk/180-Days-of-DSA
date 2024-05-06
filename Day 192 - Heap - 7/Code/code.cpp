#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Smallest Range Covering Elements from K Lists.
vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
        p;
    int minimum, maximum = INT_MIN;

    // insert first element of each row into heap
    for (int i = 0; i < nums.size(); i++)
    {
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]);
    }
    minimum = p.top().first;
    vector<int> ans(2);
    ans[0] = minimum;
    ans[1] = maximum;

    pair<int, pair<int, int>> temp;
    int row, col, elem;

    while (p.size() == nums.size())
    {
        temp = p.top();
        p.pop();

        elem = temp.first;
        row = temp.second.first;
        col = temp.second.second;

        if (col + 1 < nums[row].size())
        {
            col++;
            p.push(make_pair(nums[row][col], make_pair(row, col)));
            maximum = max(maximum, nums[row][col]);
            minimum = p.top().first;

            // If I have got smallest range
            if (maximum - minimum < ans[1] - ans[0])
            {
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }
    return ans;
}

// Q2. Construct Target Array With Multiple Sums.
bool isPossible(vector<int> &target)
{
    // maxheap
    priority_queue<long long> p;
    long long sum = 0;

    for (int i = 0; i < target.size(); i++)
    {
        p.push(target[i]);
        sum += target[i];
    }

    long long maxEle, remSum, element;
    while (p.top() != 1)
    {
        maxEle = p.top();
        p.pop();
        remSum = sum - maxEle;

        // Edge Cases
        if (remSum <= 0 || remSum >= maxEle)
            return 0;

        element = maxEle % remSum;
        if (element == 0)
        {
            if (remSum != 1)
                return 0;
            else
                return 1;
        }
        sum = remSum + element;
        p.push(element);
    }
    return 1;
}

int main() {}