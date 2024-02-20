#include <iostream>
#include<deque>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

// Implementing Deque by using Linked List.
class DequeByLL
{
    Node *front, *rear;

public:
    DequeByLL()
    {
        front = rear = NULL;
    }

    void push_front(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of Deque \n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of Deque \n";
            return;
        }
    }

    void push_back(int x)
    {
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back of Deque \n";
            return;
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed " << x << " in back of Deque \n";
            return;
        }
    }

    void pop_front()
    {
        if (front == NULL)
        {
            cout << "Deque Underflow \n";
            return;
        }
        else
        {
            Node *temp = front;
            cout << "Poppped " << temp->data << " from front of Deque \n";
            front = front->next;
            delete temp;

            if (front)
                front->prev = NULL;
            else
                rear = NULL;
        }
    }

    void pop_back()
    {
        if (front == NULL)
        {
            cout << "Deque Underflow \n";
            return;
        }
        else
        {
            Node *temp = rear;
            cout << "Poppped " << temp->data << " from back of Deque \n";
            rear = rear->prev;
            delete temp;

            if (rear)
                rear->next = NULL;
            else
                front = NULL;
        }
    }

    int start()
    {
        if (front == NULL)
            return -1;
        else
            return front->data;
    }

    int back()
    {
        if (front == NULL)
            return -1;
        else
            return rear->data;
    }
};

// Implementing Deque by using Array.
class DequeByArray
{
    int front, rear, size;
    int *arr;

public:
    DequeByArray(int n)
    {
        size = n;
        front = rear = -1;
        arr = new int[n];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void push_front(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " in front of Deque \n";
            return;
        }
        else if (isFull())
        {
            cout << "Deque Overflow \n";
            return;
        }
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
            cout << "Pushed " << x << " in front of Deque \n";
            return;
        }
    }

    void push_back(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " in back of Deque \n";
            return;
        }
        else if (isFull())
        {
            cout << "Deque Overflow \n";
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " in back of Deque \n";
            return;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow \n";
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Poppped " << arr[front] << " from front of Deque \n";
                front = rear = -1;
            }

            else
            {
                cout << "Poppped " << arr[front] << " from front of Deque \n";
                front = (front + 1) % size;
            }
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow \n";
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Poppped " << arr[rear] << " from front of Deque \n";
                front = rear = -1;
            }
            else
            {
                cout << "Poppped " << arr[rear] << " from front of Deque \n";
                rear = (rear - 1 + size) % size;
            }
        }
    }

    int start()
    {
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int back()
    {
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }
};

int main()
{
    DequeByLL d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    deque<int> d;
    d.push_front(1);
    d.push_front(12);
    d.push_front(13);
    d.push_back(13);
    d.push_back(12);
    d.push_back(1);
}