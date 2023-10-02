#include <iostream>
using namespace std;

int main()
{
    // while loop
    // int n;
    // cout << "Enter the Number : ";
    // cin >> n; // initialize
    // int i = 1;
    // while (i <= n) // break
    // {
    //     cout << i << " ";
    //     i++; // update
    // }

    // do while loop
    int n;
    cout << "Enter the Number : ";
    cin >> n; // initialize
    int sum = 0;
    int i = 1;
    do{
        sum += i;
        i++;
    } while(i <= n);

    cout<<sum;
}