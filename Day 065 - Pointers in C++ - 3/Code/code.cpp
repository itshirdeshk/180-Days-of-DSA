#include <iostream>
using namespace std;

// Pass by Pointer
void swapping(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Pass by Reference Variable
void swapping(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    char arr[5] = "1234";
    char *ptr = arr;
    cout << arr << endl;
    cout << ptr << endl;

    cout << (void *)arr << endl;
    cout << static_cast<void *>(arr) << endl;
    cout << (void *)ptr << endl;

    // cout<<&arr<<endl;

    char a = 'a';
    char *p = &a;
    cout << &a << endl;
    cout << (void *)&a << endl;
    cout << (void *)p << endl;

    // Swapping two numbers
    int first = 10, second = 20;
    cout << first << " " << second << endl;
    swapping(&first, &second);
    cout << first << " " << second << endl;

    // Pass by Reference Variable
    int num = 10;
    cout << num << endl;
    int &temp = num;
    temp++;
    cout << num << endl;

    int first = 10, second = 20;
    cout << first << " " << second << endl;
    swapping(first, second);
    cout << first << " " << second << endl;

}