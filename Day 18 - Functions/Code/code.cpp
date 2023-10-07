#include <iostream>
using namespace std;

int sum(int a, int b) // Function declaration
{
    return a + b; // Function definition
}

int mul(int a, int b)
{
    return a * b;
}

void fun()
{
    cout << "Hello Everyone\n";
}

bool prime(int n = 5) // Default Parameter
{
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void swapVal(int a, int b) // Pass By Value
{
    int c = a;
    a = b;
    b = c;
}

void swapRef(int &a, int &b) // Pass by Reference
{
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int m, n;
    cin >> m >> n;
    // cout << sum(m, n) << endl;
    // cout << mul(m, n) << endl;
    // fun();

    cout << m << " " << n << endl;
    swapVal(m, n);
    cout << m << " " << n << endl;

    swapRef(m, n);
    cout << m << " " << n;
}