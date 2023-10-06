#include <iostream>
using namespace std;

int main()
{

    // Q1. Ugly Number
    class Solution
    {
    public:
        bool isUgly(int n)
        {
            if (n <= 0)
                return false;
            while (n % 2 == 0)
                n /= 2;
            while (n % 3 == 0)
                n /= 3;
            while (n % 5 == 0)
                n /= 5;
            return (n == 1);
        }
    };

    // Q2. Squares in N*N Chessboard
    class Solution
    {
    public:
        long long squaresInChessBoard(long long N)
        {
            // code here
            return (N * (N + 1) * (2 * N + 1)) / 6;
        }
    };
}