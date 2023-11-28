#include <iostream>
using namespace std;

int main()
{
    // First Pattern
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

    // Second Pattern
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
            char alpha = 'A' + (row - 1);
            cout << alpha << " ";
        }
        cout << endl;
    }

    // Third Pattern
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

    // Fourth Pattern
    int n;
    cout << "Enter the number of rows : ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }

        for (char alpha = 'A' + (n - 1); alpha > ('A' + (n - 1)) - row; alpha--)
        {
            cout << alpha << " ";
        }
        cout << endl;
    }
}