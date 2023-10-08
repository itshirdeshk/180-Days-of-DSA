#include <iostream>
#include <cmath>
using namespace std;

// Q1. Convert lowercase char to their equivalent uppercase char.
char convertLowerToUpper(char lower)
{
    char upper = lower - 32;
    return upper;
}

// Q2. Armstrong Number
int pow(int base, int exponent)
{
    int ans = 1;
    for (int i = 1; i <= exponent; i++)
    {
        ans = ans * base;
    }

    return ans;
}

int armstrong(int num)
{
    int m = num;
    int n = num;
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }

    int ans = 0;

    while (num != 0)
    {
        int rem = num % 10;
        ans = ans + pow(rem, count);
        num /= 10;
    }

    if (m == ans)
    {
        return true;
    }
    else
        return false;
}

// Q3. Find trailing zero in a factorial
int fact(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }

    return ans;
}

// This solution is only valid upto 14.
int find(int n)
{
    int f = fact(n);
    int count = 0;
    while (f)
    {
        int rem = f % 10;
        if (rem == 0)
        {
            count++;
        }
        else
        {
            break;
        }
        f /= 10;
    }
    return count;
}

// This solution is valid to any number.
int find2(int n)
{
    int count = 0;
    while (n >= 5)
    {
        int div = n / 5;
        count = count + floor(div);
        n /= 5;
    }

    return count;
}

// Q4. Valid Rectangle
bool validRec(int a, int b, int c, int d)
{
    if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
    {
        return 1;
    }
    return 0;
}

// Q5. Total Moves for Bishop!
int solve(int A, int B)
{
    int count = 0;

    count += min(8 - A, 8 - B);
    count += min(8 - A, B - 1);
    count += min(A - 1, B - 1);
    count += min(A - 1, 8 - B);

    return count;
}

// Q6. Nim Game
bool canWinNim(int n)
{
    if (n % 4 == 0)
        return false;
    else
        return true;
}

int main()
{
    // cout << convertLowerToUpper('z');
    // cout<<pow(2, 3);
    // cout << armstrong(153);

    // cout<<find2(384);
}