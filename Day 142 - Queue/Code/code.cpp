#include <iostream>
#include<queue>
using namespace std;

// Implementing Queue using array
class Queue
{
    int *arr;
    int front, rear, size;

public:
    // Constructor
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue \n";
            return;
        }
        else if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            arr[++rear] = x;
            cout << "Pushed " << x << " into the Queue \n";
            return;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Popped " << arr[front] << " from the Queue \n";
                front = rear = -1;
            }
            else
            {
                cout << "Popped " << arr[front] << " from the Queue \n";
                front++;
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
            return arr[front];
    }
};

// Implementing Circular Queue using array
class CircularQueue
{
    int *arr;
    int front, rear, size;

public:
    // Constructor
    CircularQueue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " into the Queue \n";
            return;
        }
        else if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue \n";
            return;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "Popped " << arr[front] << " from the Queue \n";
                front = rear = -1;
            }
            else
            {
                cout << "Popped " << arr[front] << " from the Queue \n";
                front = (front + 1) % size;
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
            return arr[front];
    }
};

// Implementing Queue using Linked List
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

class QueueByLL
{
    Node *front, *rear;

public:
    QueueByLL()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void push(int x)
    {
        if (isEmpty())
        {
            front = new Node(x);
            rear = front;
            cout << "Pushed " << x << " into the Queue \n";
            return;
        }
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
            cout << "Pushed " << x << " into the Queue \n";
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            cout << "Popped " << temp->data << " from the Queue \n";
            delete temp;
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    // Queue q(5);
    // q.push(5);
    // q.push(15);
    // q.push(51);
    // q.pop();
    // cout << q.start() << endl;

    // By using STL
    queue<int> q;
    q.push(10);
    q.push(100);
    q.push(1000);

    q.pop();

    cout<<q.front()<<endl;

    cout<<q.size()<<endl;
}