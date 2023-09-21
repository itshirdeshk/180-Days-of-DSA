#include <iostream>
using namespace std;

int main()
{
    // if-else

    // 1. Two numbers are given, print the bigger number, It is given that both numbers can’t be the same.
    int num1, num2;
    cin >> num1;
    cin >> num2;

    if (num1 > num2)
    {
        cout << "1st Number is bigger";
    }
    else
    {
        cout << "2nd Number is bigger";
    }

    // 2.Age of a person is given, print Adult if his/her age is greater than 18, otherwise print Teenager.
    int age;
    cin >> age;
    if (age > 18)
    {
        cout << "Adult";
    }
    else
    {
        cout << "Teenager";
    }

    // 3. Take a number in input (ex n) and print the corresponding month to it. Ex: for n=1, print january, n=2, print feburary like this you need to give output. It is given that n will be greater than 0 and less than 13.
    int month;
    cout << "Enter the number of the Month: ";
    cin >> month;

    if (month == 1)
    {
        cout << "January";
    }
    else if (month == 2)
    {
        cout << "Feburuary";
    }
    else if (month == 3)
    {
        cout << "March";
    }
    else if (month == 4)
    {
        cout << "April";
    }
    else if (month == 5)
    {
        cout << "May";
    }
    else if (month == 6)
    {
        cout << "June";
    }
    else if (month == 7)
    {
        cout << "July";
    }
    else if (month == 8)
    {
        cout << "August";
    }
    else if (month == 9)
    {
        cout << "September";
    }
    else if (month == 10)
    {
        cout << "October";
    }
    else if (month == 11)
    {
        cout << "November";
    }
    else if (month == 12)
    {
        cout << "December";
    }

    // Loops
    // 1. Print “India will win the World Cup 2023”, 20 times.

    for (int i = 1; i <= 20; i++)
    {
        cout << "India will win the World Cup 2023";
    }

    // 2. Print all Odd numbers from 1 to n, take n as an input from the user.
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << endl;
        }
    }

    // 3. Print all numbers from 1 to n, which is divisible by 4. Take n as an input from the user.
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
        {
            cout << i << endl;
        }
    }
}