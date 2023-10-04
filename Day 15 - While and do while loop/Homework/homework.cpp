#include <iostream>
using namespace std;

void main()
{
    // Q1. Take a number n from the user and print all the even numbers between 1 and n(inclusive). Do this using while and do while loop separately.

    // By using while loop
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int i = 1;

    while (i <= num)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
        i++;
    }

    // By using do while loop
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int i = 1;

    do
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
        i++;
    } while (i <= num);

    // Q2. Find the factorial of a number n using a while loop and do a while loop.

    // By using while loop
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int fact = 1;
    while (num > 1)
    {
        fact *= num;
        num--;
    }

    // By using do while loop
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int fact = 1;
    do
    {
        fact *= num;
        num--;
    } while (num > 1);

    // Q3. Given a number n, print all the numbers from 1 to n(inclusive) which are not divisible by 3 and 5. (use Continue here).
    int num;
    cout << "Enter the number : ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            continue;
        }
        else
        {
            cout << i << " ";
        }
    }

    // Q4. Given a number n, print the corresponding month of it. For n=1, print Jan, n=2, print Feb…, if the user puts any invalid number, don’t do anything. (Use switch here)

    int month;
    cout << "Enter the month : ";
    cin >> month;

    switch (month)
    {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "Feburary";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "November";
        break;
    case 12:
        cout << "December";
        break;
    default:
        cout<<"Invalid Month";
    }

    // Q5. Print all the Capital and small letters using a while loop. It means A-Z, then a-z.
    char alpha = 'A';
    while(alpha <= 'Z') {
        cout<<alpha<<" ";
        alpha += 1;
    }

    char alpha = 'a';
    while(alpha <= 'z') {
        cout<<alpha<<" ";
        alpha += 1;
    }

    // Q6. Give a number n, find if it is prime or not, use a while loop and break here to solve it.
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int i = 2;
    int flag = 0;

    while(i < num) {
        if(num % i == 0) {
            flag = 1;
            break;
        }
        i++;
    }

    if(flag == 0) {
        cout<<"Prime Number";
    } else {
        cout<<"Not a Prime Number";
    }
}