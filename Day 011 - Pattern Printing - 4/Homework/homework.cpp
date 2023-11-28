#include <iostream>
using namespace std;

int main()
{
    // First Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << " ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Second Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << "  ";
        }
        for (int col = 1; col <= 2 * row - 1; col++)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    // Third Pattern
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= n - row; col++) {
            cout<<"  ";
        }
        for(char col = 'A'; col <= 'A' + (row - 1); col++) {
            cout<<col<<" ";
        }
        for(char col = 'A' + (row - 2); col >= 'A'; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    // Fouth Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n - row; col++)
        {
            cout << " ";
        }

        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int row = n; row >= 1; row--)
    {
        for (int col = n - row; col >= 1; col--)
        {
            cout << " ";
        }

        for (int col = row; col >= 1; col--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}