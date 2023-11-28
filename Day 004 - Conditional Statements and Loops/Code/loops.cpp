#include <iostream>
using namespace std;

int main()
{
    for (int count = 1; count <= 5; count++)
    {
        cout << "Coder Army \n";
    }

    // Print square to the given number from 1
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i * i << "\n";
    }

    // Print even number upto n
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << endl;
        }
    }

    // you can also do this
    for (int i = 2; i <= n; i = i + 2)
    {
        cout << i << endl;
    }
}