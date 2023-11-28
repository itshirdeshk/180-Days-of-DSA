#include <iostream>
using namespace std;

int main()
{
    // First Pattern
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= n - row; col++) {
            cout<<"  ";
        }
        for(int col = 1; col <= 2 * row - 1; col++) {
            cout<<"* ";
        }
        cout<<endl;
    }

    // Second Pattern
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= n - row; col++) {
            cout<<"  ";
        }
        for(int col = 1; col <= row; col++) {
            cout<<col<<" ";
        }
        for(int col = row - 1; col >= 1; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    // Third Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = n; row >= 1; row--)
    {
        for (int col = n - row; col >= 1; col--)
        {
            cout << "  ";
        }
        for (int col = 1; col <= 2 * row - 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Fourth Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = n; row >= 1; row--)
    {
        for(int col = 1; col <= row; col++) {
            cout<<"* ";
        }

        for(int col = 1; col <= 2 * (n - row); col++) {
            cout<<"  ";
        }

        for(int col = 1; col <= row; col++) {
            cout<<"* ";
        }
        cout << endl;
    }

    for (int row = 1; row <= n; row++)
    {
        for(int col = row; col >= 1; col--) {
            cout<<"* ";
        }

        for(int col = 2 * (n - row); col >= 1; col--) {
            cout<<"  ";
        }

        for(int col = row; col >= 1; col--) {
            cout<<"* ";
        }
        cout << endl;
    }

    // Fifth Pattern
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++) {
            cout<<"* ";
        }

        for(int col = 1; col <= 2 * (n - row); col++) {
            cout<<"  ";
        }

        for(int col = 1; col <= row; col++) {
            cout<<"* ";
        }
        cout << endl;
    }

    for (int row = n - 1; row >= 1; row--)
    {
        for(int col = row; col >= 1; col--) {
            cout<<"* ";
        }

        for(int col = 2 * (n - row); col >= 1; col--) {
            cout<<"  ";
        }

        for(int col = row; col >= 1; col--) {
            cout<<"* ";
        }
        cout << endl;
    }

    // Sixth Pattern
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