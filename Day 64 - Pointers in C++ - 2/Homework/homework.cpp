#include<iostream>
using namespace std;

int main () {
    // 1. Print the address of the first index of the char array in c++.
    char arr[5] = "abcd";
    cout<<&arr;

    // 2. Print the address of the char variable in c++.
    char a = 'a';

    // 3. Print the address of String in c++.
    string hey = "Hello";
    cout<<&hey<<endl;

    // 4. Given an array in c++,
    // int arr[5] = {1,2,3,4,5};
    // What is the difference between arr and &arr. Try to explore it on your own.
    int arr[5] = {1,2,3,4,5};
    cout<<arr<<endl;
    cout<<&arr<<endl;

    cout<<*arr<<endl;
    cout<<*(&arr)<<endl;

    // 5. int arr[5] = {1,2,3,4,5};
    // Create a pointer which will store the address of the last element. Then print all the elements from the last index to 0th index with the help of a pointer.
    int arr1[5] = {1,2,3,4,5};
    int *ptr = arr1 + 4;

    for(int i = 4; i >= 0; i--)
        cout<<*ptr--<<endl;
}