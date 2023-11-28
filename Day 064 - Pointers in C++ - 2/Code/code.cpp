#include<iostream>
#include<vector>
using namespace std;

int main () {

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // Print the address of first element or 0 index
    cout<<arr<<endl;
    cout<<arr + 0<<endl;
    cout<<&arr[0]<<endl;
    cout<<ptr<<endl;

    // Print the address of second element or 1 index
    cout<<arr + 1<< endl;
    cout<<&arr[1]<< endl;

    // Print the value of first element or - index
    cout<<arr[0]<< endl;
    cout<<*arr<< endl;
    cout<<*(arr + 0)<< endl;
    cout<<*ptr<< endl;

    // Print all the addresses
    for(int i = 0; i < 5; i++)
        cout<<arr + i<<endl;

    // Print all the values
    for(int i = 0; i < 5; i++)
        cout<<*(arr + i)<<endl;

    // Print all the values using pointer
    for(int i = 0; i < 5; i++)
        cout<<ptr[i]<<endl;

    // Print all the addresses using pointer
    for(int i = 0; i < 5; i++)
        // cout<<&ptr[i]<<endl;
        cout<<(ptr + i)<<endl;

    // Arithmetic Operations
    for(int i = 0; i < 5; i++)
        cout<<*ptr++<<" ";

    ptr = ptr + 3;
    cout<<*ptr<< " ";

    ptr = ptr - 2;
    cout<<*ptr<<endl;
}