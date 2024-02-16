#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// Q1. Get minimum element from stack.
// Method 1:
class Solution
{
    int minEle;
    stack<int> st1;
    stack<int> st2;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (st1.empty())
            return -1;
        else
            return st2.top();
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (st1.empty())
            return -1;
        else
        {
            int element = st1.top();
            st1.pop();
            st2.pop();
            return element;
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {

        // Write your code here
        if (st1.empty())
        {
            st1.push(x);
            st2.push(x);
        }
        else
        {
            st1.push(x);
            st2.push(min(x, st2.top()));
        }
    }
};

// Method 2:
class Solution
{
    int minEle;
    stack<int> st1;

public:
    /*returns min element from stack*/
    int getMin()
    {

        // Write your code here
        if (st1.empty())
            return -1;
        else
            return st1.top() % 101;
    }

    /*returns poped element from stack*/
    int pop()
    {

        // Write your code here
        if (st1.empty())
            return -1;
        else
        {
            int element = st1.top() / 101;
            st1.pop();
            return element;
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {

        // Write your code here
        if (st1.empty())
        {
            st1.push(x * 101 + x);
        }
        else
        {
            st1.push(x * 101 + min(x, st1.top() % 101));
        }
    }
};

// Q2. Maximum of minimum for every window size.
// Method 1:
vector<int> maxOfMin(int arr[], int n)
{
    // Your code here
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int num = INT_MAX;
            for (int k = j; k < j + i + 1; k++)
            {
                num = min(num, arr[k]);
            }
            ans[i] = max(ans[i], num);
        }
    }
    return ans;
}

// Method 2:
vector<int> maxOfMin(int arr[], int n)
{
    // Your code here
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int index = st.top();
            st.pop();
            if (st.empty())
            {
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int index = st.top();
        st.pop();
        if (st.empty())
        {
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        else
        {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }

    for (int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    return ans;
}

int main() {}