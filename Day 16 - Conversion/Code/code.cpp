#include <iostream>
using namespace std;

int main()
{
    // Decimal to Binary
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 2;
        // rem = num & 1;

        ans = rem * mul + ans;
        // ans *= mul + rem;

        num = num / 2;
        // num = num >> 1;

        mul *= 10;
    }
    cout << ans;

    // Binary to Decimal
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 10;

        ans = rem * mul + ans;
        // ans *= mul + rem;

        num = num / 10;

        mul *= 2;
    }
    cout << ans;

    // Decimal to Octal
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 8;

        ans = rem * mul + ans;

        num = num / 8;

        mul *= 10;
    }
    cout << ans;

    // Octal to Decimal
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 10;

        ans = rem * mul + ans;
        // ans *= mul + rem;

        num = num / 10;

        mul *= 8;
    }
    cout << ans;

    // Octal to Binary

    int num;
    cout << "Enter the number : ";
    cin >> num;

    // Octal to Decimal
    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 10;

        ans = rem * mul + ans;
        // ans *= mul + rem;

        num = num / 10;

        mul *= 8;
    }

    // Decimal to Binary
    int ans1 = 0;
    rem = 0, mul = 1;
    while (ans > 0)
    {
        rem = ans % 2;
        // rem = num & 1;

        ans1 = rem * mul + ans1;
        // ans *= mul + rem;

        ans = ans / 2;
        // num = num >> 1;

        mul *= 10;
    }
    cout << ans1;

    // Binary to Octal
    int num;
    cout << "Enter the number : ";
    cin >> num;

    // Binary to Decimal
    int ans = 0, rem = 0, mul = 1;
    while (num > 0)
    {
        rem = num % 10;

        ans = rem * mul + ans;
        // ans *= mul + rem;

        num = num / 10;

        mul *= 2;
    }

    // Decimal to Octal
    int ans1 = 0;
    rem = 0, mul = 1;
    while (ans > 0)
    {
        rem = ans % 8;

        ans1 = rem * mul + ans1;

        ans = ans / 8;

        mul *= 10;
    }
    cout << ans1;
}