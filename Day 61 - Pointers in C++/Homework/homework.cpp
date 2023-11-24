#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int *p = &num;

    num = *p + 5;

    cout << num;
}