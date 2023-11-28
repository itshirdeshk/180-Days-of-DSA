#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << row << " ";
        }
        cout << endl;
    }

    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (char alpha = 'A'; alpha <= 'A' + (row - 1); alpha++)
        {
            cout << alpha << " ";
        }
        cout << endl;
    }

    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (int col = row; col >= 1; col--)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}