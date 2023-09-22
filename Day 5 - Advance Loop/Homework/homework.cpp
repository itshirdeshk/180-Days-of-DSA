#include <iostream>
using namespace std;

int main()
{
    // 1. Print number from 280 to 250 with the help of for loop.
    for(int i = 280; i >= 250; i--) {
        cout<<i<<" ";
    }

    // 2. Print char from ‘A’ to ‘Z’ with the help of a for loop.
    for(char alpha = 'A'; alpha <= 'Z'; alpha++) {
        cout<<alpha<<" ";
    }

    // 3. Print char from ‘Z’ to ‘A’ with the help of a for loop.
    for(char alpha = 'Z'; alpha <= 'A'; alpha--) {
        cout<<alpha<<" ";
    }

    // 4. There is an Arithmetic Progression, First number is 220 and Common Difference is 7. So print all the numbers from 220 to 730 which follow the AP.
    for(int i = 220; i <= 730; i = i + 7) {
        cout<<i<<" ";
    }

    // 5. Print Sum of square of first n natural number.
    int sum = 0;
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    for(int i = 1; i <= n; i++) {
        sum = sum + (i * i);
    }
    cout<<sum;

    // 6. Print Sum of cube of first n natural number
    int sum = 0;
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    for(int i = 1; i <= n; i++) {
        sum = sum + (i * i * i);
    }
    cout<<sum;

    // 7. Print n’th Fibonacci number.
    int last = 0;
    int prev = 1;
    int current, n;

    cout << "Enter the n'th number : ";
    cin >> n;

    if (n == 1)
    {
        cout << last;
    }
    else if (n == 2)
    {
        cout << prev;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            current = last + prev;
            last = prev;
            prev = current;
        }
    }

    cout << current;
}