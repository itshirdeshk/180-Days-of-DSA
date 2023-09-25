#include <iostream>
using namespace std;

int main()
{
    int row;
    int col;

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << "10"
                 << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << row << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 5; col >= 1; col--)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << col * col << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << col * col * col << " ";
        }
        cout << endl;
    }

    for (row = 1; row <= 5; row++)
    {
        for (char column = 'a'; column <= 'e'; column++)
        {
            cout << column << " ";
        }
        cout << endl;
    }

    char name = 'a';
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << name << " ";
        }
        name++;
        cout << endl;
    }

    int count = 1;
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    // Another Method
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << (row - 1) * 5 + col << " ";
        }
        cout << endl;
    }
}