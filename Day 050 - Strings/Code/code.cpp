#include <iostream>
using namespace std;

int main()
{
    char arr[] = {'a', 'p', 'p', 'l', 'e'};
    for(int i = 0; i < 5; i++)
        cout<<arr[i];

    char arr[20];
    cin>>arr;
    cout<<arr;

    string S;
    // cin>>S;
    // cout<<S;

    getline(cin, S);
    cout<<S<<" ";
    // cout<<S.size();

    string s1 = "Hello", s2 = "World";
    string s3 = s1 + s2;
    cout<<s3;

    string s4 = "Hirdesh is a \"good\" boy";
    cout<<s4;

    // Reverse a String
    string s = "Hirdesh";
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++, end--;
    }

    cout << s;

    // Calculate the length of the string
    int size = 0;
    while (s[size] != '\0')
        size++;

    cout << size;

    // Palindrome String
    string s2 = "naman";
    start = 0, end = s2.size() - 1;
    while (start < end)
    {
        if (s2[start] != s2[end])
        {
            cout << "String is not a palindrome";
            return;
        }
        else
        {
            start++, end--;
        }
    }

    cout << "String is a palindrome";
}