#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter your first number : \t";
    cin >> a;

    cout << "Enter your second number : \t";
    cin >> b;

    cout << "Sum of number is : \t" << a + b;

    // Type Casting
    int a = 65;
    char c = 'b';
    // a = c;
    c = a;

    cout << c;
}