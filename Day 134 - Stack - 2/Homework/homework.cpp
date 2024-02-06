#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// Q1. Backspace String Compare.
bool backspaceCompare(string s, string t)
{
    stack<char> st1;
    stack<char> st2;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            if (!st1.empty())
                st1.pop();
        }
        else
            st1.push(s[i]);
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '#')
        {
            if (!st2.empty())
                st2.pop();
        }
        else
            st2.push(t[i]);
    }

    while (!st1.empty() && !st2.empty())
    {
        if (st1.top() == st2.top())
        {
            st1.pop();
            st2.pop();
        }
        else
            return 0;
    }

    return st1.empty() && st2.empty();
}

// Q2. Special Stack.
void push(stack<int> &s, int a)
{
    // Your code goes here
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    int value = s.top();
    s.pop();
    return value;
}

int getMin(stack<int> &s)
{
    // Your code goes here
    stack<int> st;
    int min = INT_MAX;

    while (!s.empty())
    {
        if (s.top() < min)
        {
            min = s.top();
            st.push(s.top());
            s.pop();
        }
        else
        {
            st.push(s.top());
            s.pop();
        }
    }

    while (!st.empty())
    {
        s.push(st.top());
        st.pop();
    }
    return min;
}

// Q3.

// Q4. Minimum Add to Make Parentheses Valid.
int minAddToMakeValid(string s)
{
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')')
        {
            if (left)
                left--;
            else
                right++;
        }
    }
    return left + right;
}

int main() {}