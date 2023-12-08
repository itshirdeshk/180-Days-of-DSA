#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int pow(int num, int n)
{
    if (n == 1)
        return num;
    return num * pow(num, n - 1);
}

int sqSum(int n)
{
    if (n == 1)
        return 1;
    return n * n + sqSum(n - 1);
}

int main()
{
    // Print Factorial of a number
    int n = 5;
    cout << fact(n);

    // Print sum of a N numbers
    int n = 5;
    cout << sum(n);

    // Print Power
    int n = 5;
    cout << pow(n, 5);

    // Print sum of square of N numbers
    int n = 5;
    cout << sqSum(n);

}