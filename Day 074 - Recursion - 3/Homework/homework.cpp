#include <iostream>
using namespace std;

int cubeSum(int n)
{
    if (n == 1)
        return 1;
    return n * n * n + cubeSum(n - 1);
}

bool prime(int num, int n)
{
    if (num == n)
        return 1;
    else
    {
        if (n % num != 0)
        {
            return prime(num + 1, n);
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    // // Q1. Sum of cubes of N natural numbers using Recursion.
    // int n = 5;
    // cout << cubeSum(n);

    // Q2.

    // Q3. Given a Number N, check whether it is prime or not using Recursion.
    int n = 5;
    if (prime(2, n))
        cout << "Prime";
    else
        cout << "Not Prime";
}