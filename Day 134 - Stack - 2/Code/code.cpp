#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Q1. Reverse String.
void reverseString(vector<char> &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    int i = 0;
    while (!st.empty())
    {
        s[i++] = st.top();
        st.pop();
    }
}

// Q2. Insert an Element at the Bottom of a Stack.
stack<int> insertAtBottom(stack<int> St, int X)
{
    stack<int> helper;
    while (!St.empty())
    {
        helper.push(St.top());
        St.pop();
    }

    St.push(X);

    while (!helper.empty())
    {
        St.push(helper.top());
        helper.pop();
    }
    return St;
}

// Q3. Make the array beautiful.
vector<int> makeBeautiful(vector<int> arr)
{
    // code here
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
            s.push(arr[i]);
        else if (arr[i] >= 0)
        {
            if (s.top() >= 0)
                s.push(arr[i]);
            else
                s.pop();
        }
        else
        {
            if (s.top() < 0)
                s.push(arr[i]);
            else
                s.pop();
        }
    }

    vector<int> ans(s.size());
    int i = s.size() - 1;
    while (!s.empty())
    {
        ans[i--] = s.top();
        s.pop();
    }
    return ans;
}

// Q4. String Manipulation.
int removeConsecutiveSame(vector<string> v)
{
    // Your code goes here
    stack<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            s.push(v[i]);
        else if (s.top() == v[i])
            s.pop();
        else
            s.push(v[i]);
    }
    return s.size();
}

// Q5. Valid Parenthesis.
// Method 1:
bool check(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            if (s.empty())
                return 0;
            else
                s.pop();
        }
    }
    return s.empty();
}

// Method 2:
bool check(string str)
{
    int left = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            left++;
        }
        else
        {
            if (left == 0)
                return 0;
            else
                left--;
        }
    }

    return left == 0;
}

// Q6. Minimum Add to Make Parentheses Valid.
int minAddToMakeValid(string s)
{
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.empty())
                count++;
            else
                st.pop();
        }
    }

    return count + st.size();
}

// Q7. Valid Parentheses.
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return 0;
            else if (s[i] == ')')
            {
                if (st.top() != '(')
                    return 0;
                else
                    st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.top() != '[')
                    return 0;
                else
                    st.pop();
            }
            else
            {
                if (st.top() != '{')
                    return 0;
                else
                    st.pop();
            }
        }
    }
    return st.empty();
}

// Q8. Print Bracket Number.
vector<int> bracketNumbers(string S)
{
    // Your code goes here
    vector<int> ans;
    int count = 0;
    stack<int> st;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        else if (S[i] == ')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

// Q9. Get min at pop.
stack<int> _push(int arr[], int n)
{
    // your code here
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            st.push(arr[i]);
        else
            st.push(min(arr[i], st.top()));
    }

    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s)
{
    // your code here
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {}