#include <iostream>
#include<stack>
using namespace std;

// Implementing stack by using array.
// class stack
// {
//     int *arr;
//     int size;
//     int top;

// public:
//     // We are using a flag variable to check whether the stack is empty or not.
//     // If flag == 1 then stack is empty otherwise stack is not empty.
//     int flag;
//     stack(int s)
//     {
//         size = s;
//         top = -1;
//         arr = new int[s];
//         flag = 1;
//     }

//     void push(int value)
//     {
//         if (top == size - 1)
//         {
//             cout << "Stack Overflow \n";
//             return;
//         }
//         top++;
//         arr[top] = value;
//         cout << "Pushed " << value << " into the stack \n";
//         flag = 0;
//     }
//     void pop()
//     {
//         if (top == -1)
//         {
//             cout << "Stack Underflow \n";
//             return;
//         }
//         top--;
//         cout << "Popped " << arr[top + 1] << " from the stack \n";
//         if (top == -1)
//             flag = 1;
//     }

//     int peek()
//     {
//         if (top == -1)
//         {
//             cout << "Stack is Empty \n";
//             return -1;
//         }
//         return arr[top];
//     }

//     bool isEmpty()
//     {
//         // if(top == -1) return 1;
//         // return 0;
//         return top == -1;
//     }

//     int isSize()
//     {
//         return top + 1;
//     }
// };

// Implementing stack by using Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "Stack Overflow";
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushed " << value << " into the stack \n";
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow";
            return;
        }
        else
        {
            Node *temp = top;
            cout << "Popped " << top->data << " from the stack \n";
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty";
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    int isSize()
    {
        return size;
    }
};

int main()
{
    // Array implementation of stack.
    // stack s(5);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.pop();
    // s.pop();
    // s.pop();

    // We can't insert negative values but by using a flag variable, we can insert negative values.
    // s.push(-1);
    // int value = s.peek();
    // if (s.flag == 0)
    //     cout << value << endl;

    // Linked List implementation of stack.
    // Stack S;
    // S.push(1);
    // S.push(2);
    // S.push(3);
    // S.pop();

    stack<int> s;
    s.push(6);
    s.push(7);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
}