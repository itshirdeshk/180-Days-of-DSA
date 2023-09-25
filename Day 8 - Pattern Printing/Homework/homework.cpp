#include <iostream>
using namespace std;

int main()
{
    int row, col;

    // First Pattern
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << "4"
                 << " ";
        }
        cout << endl;
    }

    // Second Pattern
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << col * col << " ";
        }
        cout << endl;
    }

    // Third Pattern
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 5; col++)
        {
            cout << col * col * col << " ";
        }
        cout << endl;
    }

    // Fourth Pattern
    for (row = 1; row <= 5; row++)
    {
        for (char column = 'F'; column <= 'K'; column++)
        {
            cout << column << " ";
        }
        cout << endl;
    }
}