#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q1. Make Array Zero by Subtracting Equal Amounts
int minimumOperations(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            s.insert(nums[i]);
    }

    return s.size();
}

// Q2. Relative Ranks.
vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> p;
    pair<int, int> pairs;
    int n = score.size();
    vector<string> ans(n);

    for (int i = 0; i < n; i++)
    {
        p.push(make_pair(score[i], i));
    }

    int count = 1;

    while (!p.empty())
    {
        if (count == 1)
        {
            pairs = p.top();
            p.pop();

            ans[pairs.second] = "Gold Medal";
            count++;
        }
        else if (count == 2)
        {
            pairs = p.top();
            p.pop();

            ans[pairs.second] = "Silver Medal";
            count++;
        }
        else if (count == 3)
        {
            pairs = p.top();
            p.pop();

            ans[pairs.second] = "Bronze Medal";
            count++;
        }
        else
        {
            pairs = p.top();
            p.pop();

            ans[pairs.second] = to_string(count);
            count++;
        }
    }
    return ans;
}

// Q3. Minimum Amount of Time to Fill Cups.
int fillCups(vector<int> &amount)
{
    priority_queue<int> p;
    for (auto x : amount)
    {
        if (x)
            p.push(x);
    }
    int ans = 0;
    while (p.size() > 1)
    {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();

        if (a > 1)
            p.push(a - 1);
        if (b > 1)
            p.push(b - 1);

        ans++;
    }
    return p.empty() ? ans : ans + p.top();
}

int main() {}