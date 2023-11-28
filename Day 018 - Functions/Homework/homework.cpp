#include <iostream>
using namespace std;

// Q1: Find the cube of a number using Function.
int cube(int n)
{
    return n * n * n;
}

// Q2. Reverse a number n using Function, Constraints: -5000<=n<=5000
int reverse(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }

    return ans;
}

// Q3. There are three numbers a,b,c. Put the value of a into b, put value of b into c and put value of c into a. Do it using Function.
void put(int &a, int &b, int &c)
{
    int d = a;
    int e = b;
    int f = c;
    b = d;
    c = e;
    a = f;
}

// Q4. Swap 2 numbers a, b without using extra variables. Range of (-10000<=a,b<=100000).
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Q5. Print “Hello Coder Army” n times using Function.
void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Hello Coder Army \n";
    }
}

// Q6. Given two numbers n, r. Find nCr (Combination). Use Function here.
int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }

    return ans;
}

int comb(int n, int r)
{
    int ans = (fact(n)) / (fact(n - r) * fact(r));
    return ans;
}

int main()
{
    cout << reverse(234);
    cout << reverse(-234);

    cout << comb(5, 2);
}