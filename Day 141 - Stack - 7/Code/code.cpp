#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1. Implement two stacks in an array.
class twoStacks
{
public:
    int *arr;
    int top1, top2;
    int size = 100;

    twoStacks()
    {
        arr = new int[100];
        top1 = -1, top2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 + 1 == top2)
            return;
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 - 1 == top1)
            return;
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
            return -1;
        int element = arr[top1--];
        return element;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
            return -1;
        int element = arr[top2++];
        return element;
    }
};

// Q2. N Stacks In An Array.
class Node
{
public:
    int index;
    Node *next;

    Node(int x)
    {
        index = x;
        next = NULL;
    }
};

class NStack
{
public:
    stack<int> st;
    int *arr;
    Node **top;

    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        arr = new int[S];
        top = new Node *[N];
        for (int i = 0; i < N; i++)
            top[i] = NULL;
        for (int i = 0; i < S; i++)
            st.push(i);
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if (st.empty())
            return 0;

        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp->next = top[m - 1];
        top[m - 1] = temp;
        st.pop();
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if (top[m - 1] == NULL)
            return -1;

        int element = arr[top[m - 1]->index];
        st.push(top[m - 1]->index);
        top[m - 1] = top[m - 1]->next;
        return element;
    }
};


int main() {}