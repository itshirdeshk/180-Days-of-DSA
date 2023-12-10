#include <iostream>
using namespace std;

// Q1. Fibonacci Number.
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Q2. Climbing Stairs.
int climbStairs(int n)
{
    if (n <= 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// Q3. GCD of two numbers.
int gcd(int A, int B)
{
    // code here
    if (B == 0)
        return A;
    return gcd(B, A % B);
}


int main() {}