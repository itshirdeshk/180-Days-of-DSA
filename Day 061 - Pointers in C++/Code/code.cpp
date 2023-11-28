#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a = 10;
    cout << &a << endl;

    int *ptr = &a;
    cout << ptr << endl;

    cout << sizeof(ptr) << endl;
    cout << *ptr << endl;

    int b = 15;
    ptr = &b;

    cout << ptr << endl;
}