#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Q2. Queue Reversal.
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    return q;
}

// Q3. Reverse First K elements of Queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    int n = q.size();

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}

// Q4. Time Needed to Buy Tickets.
// Method 1:
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q;

    for (int i = 0; i < tickets.size(); i++)
        q.push(i);

    int time = 0;

    while (tickets[k] != 0)
    {
        tickets[q.front()]--;
        if (tickets[q.front()])
            q.push(q.front());
        q.pop();
        time++;
    }

    return time;
}

// Method 2:
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    int time = 0;
    for (int i = 0; i <= k; i++)
    {
        time += min(tickets[k], tickets[i]);
    }

    for (int i = k + 1; i < n; i++)
    {
        time += min(tickets[k] - 1, tickets[i]);
    }

    return time;
}

// Q5. Implement Queue using Stacks.
class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue()
    {
    }

    bool empty()
    {
        return st1.empty() && st2.empty();
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (empty())
            return 0;
        if (!st2.empty())
        {
            int ele = st2.top();
            st2.pop();
            return ele;
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int ele = st2.top();
            st2.pop();
            return ele;
        }
    }

    int peek()
    {
        if (empty())
            return 0;
        if (!st2.empty())
        {
            return st2.top();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};

// Q6. Implement Stack using Queues.
// Method 1:
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }

    void push(int x)
    {
        if (empty())
            q1.push(x);
        else if (q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    int pop()
    {
        if (empty())
            return 0;
        else if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }

            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }

    int top()
    {
        if (empty())
            return 0;
        else if (q1.empty())
        {
            return q2.back();
        }
        else
        {
            return q1.back();
        }
    }
};

// Method 2:
class MyStack
{
public:
    queue<int> q1;
    MyStack() {}

    bool empty()
    {
        return q1.empty();
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (empty())
            return 0;
        int n = q1.size() - 1;
        while (n--)
        {
            q1.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top()
    {
        if (empty())
            return 0;
        return q1.back();
    }
};

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Q1. Print all the values of queue.
    int n = q.size();
    while (n--)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}