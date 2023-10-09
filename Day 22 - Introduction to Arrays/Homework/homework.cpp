#include <iostream>
using namespace std;

int main()
{
    // Q1. Take 20 elements from user input and find its sum with the help of an array.
    int arr[20];

    cout<<"Enter 20 Elements : "<<endl;
    for(int i = 0; i < 20; i++) {
        cin>>arr[i];
    }

    cout<<endl;

    int sum = 0;
    for(int i = 0; i < 20; i++) {
        sum += arr[i];
    }

    cout<<sum<<" ";

    // Q2. Calculate the average of elements in an array of size 18.
    int arr[18];

    cout<<"Enter 20 Elements : "<<endl;
    for(int i = 0; i < 18; i++) {
        cin>>arr[i];
    }

    cout<<endl;

    int sum = 0;
    for(int i = 0; i < 18; i++) {
        sum += arr[i];
    }

    cout<<sum / 18<<" ";

    // Q3. Find the index of a specific element in an array, if the element is nor present, print -1. Ask the size of the array from the user and then implement it.
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int arr[size];

    cout<<"Enter the Elements : "<<endl;
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    int num;
    cout<<"Enter the element you want to search : ";
    cin>>num;

    int flag = 0;
    int loc = 0;

    for(int i = 0; i < size; i++) {
        if(num == arr[i]) {
            loc = i;
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        cout<<loc<<endl;
    else
        cout<<-1;

    // Q4. Create an array of char types and store ‘a’ to ‘z’ in it. Then print the element of the arrays.
    char arr[26];

    cout<<"Enter the Alphabets : ";
    for(int i = 0; i < 26; i++) {
        cin>>arr[i];
    }

    for(int i = 0; i < 26; i++) {
        cout<<arr[i];
    }

    // Q5. Find the second largest element in an array of unique elements of size n. Where n>3.
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int max1 = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == max)
        {
            continue;
        }
        else if (arr[i] > max1)
        {
            max1 = arr[i];
        }
    }

    cout << max1 << endl;

    // Q6. Find the third smallest element in an array of unique elements size n. Where n>3.
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    int min1 = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == min)
        {
            continue;
        }
        else if (arr[i] < min1)
        {
            min1 = arr[i];
        }
    }

    int min2 = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == min)
        {
            continue;
        }
        else if (arr[i] == min1)
        {
            continue;
        }
        else if (arr[i] < min2)
        {
            min2 = arr[i];
        }
    }

    cout << min2 << endl;

    // Q7. What is Byte addressable?
    // ​Byte addressing means memory is organized and accessed as a sequence of bytes.
}