#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Q1. Largest Rectangle in Histogram.
// Method 1:
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // Next Smallest left
    vector<int> left(n);
    // Next Smallest right
    vector<int> right(n);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        right[st.top()] = n;
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}

// Method 2:
int largestRectangleArea(vector<int> &heights)
{
    int ans = 0, index, n = heights.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            index = st.top();
            st.pop();
            if (!st.empty())
                ans = max(ans, heights[index] * (i - st.top() - 1));
            else
                ans = max(ans, heights[index] * i);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        index = st.top();
        st.pop();
        if (!st.empty())
            ans = max(ans, heights[index] * (n - st.top() - 1));
        else
            ans = max(ans, heights[index] * n);
    }
    return ans;
}

// Q2.
int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = 0, row = matrix.size(), col = matrix[0].size();
    vector<int> heights(col, 0);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j] += 1;
        }
        ans = max(ans, largestRectangleArea(heights));
    }
    return ans;
}

// Q3.


int main() {}