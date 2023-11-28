#include <iostream>
using namespace std;

int main()
{
    int pkg;
    cin >> pkg;

    if (pkg > 10)
    {
        cout << "Accepted";
    }
    else
    {
        cout << "Rejected";
    }

    // Another Example
    int marks;
    cin >> marks;

    // if you have single statement then it is not neccessary to use parenthesis
    if (marks > 33)
        cout << "Pass";
    else
        cout << "Fail";

    // Even or Odd
    int num;
    cin >> num;
    if (num % 2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    // Check the number is +ve, -ve or zero
    int num;
    cin >> num;
    if (num > 0)
    {
        cout << "Positive";
    }

    else if (num == 0)
    {
        cout << "Zero";
    }
    else
    {
        cout << "Negative";
    }
}