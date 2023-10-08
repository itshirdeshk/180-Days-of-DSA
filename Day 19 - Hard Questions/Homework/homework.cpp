#include <iostream>
#include<math.h>
using namespace std;

// Q1. Distribute in Circle!
int solve(int A, int B, int C)
{
    return (C + A - 1) % B;
}

// Q2. Number of 1 bits
int setBits(int N)
{
    // Write Your Code here
    int setBits = 0;

    while (N > 0)
    {
        N = N & (N - 1);
        setBits++;
    }

    return setBits;
}

// Another Solution
int setBits(int N)
{
    // USING BINARY OPERATORS
    int count = 0;
    while (N)
    {
        int bit = N & 1;
        // rightmost bit is 1 , then count increased
        if (bit == 1)
            count++;
        // shift towards right to keep counting all bits (left to right) individualy
        N = N >> 1;
    }
    return count;
}

// Q3. Bit Difference
int countBitsFlip(int a, int b)
{

    // Your logic here
    int count = 0;
    while (a != 0 || b != 0)
    {

        if ((a & 1) != (b & 1))
        {
            count++;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return count;
}

// Q4. Find 5 inbuilt function in c++ like min or max etc and write a code around them.
void inBuiltFun(int a, int b, int c) {
    // 1. Calculate the power.
    cout<<pow(a, b);

    // 2. Calculate the square root
    cout<<sqrt(a);

    // 3. Calculate the floor of any number.
    cout<<floor(b);

    // 4. Calculate the ceil of any number.
    cout<<ceil(c);

    // 5. Calculate the absolute value of any number.
    cout<<abs(a);
}

int main()
{

}