#include <iostream>
using namespace std;

int main()
{
    // Q1.
    int arr[3][4];
    cout << arr << endl;
    cout << arr[0] << endl;
    cout << arr[0][0] << endl;

    // Now, let's discuss the output:

    // 1. cout << arr;: This will print the address of the entire 2D array. It will be the address of the first element of the first row (arr[0][0]).

    // 2. cout << arr[0];: This will print the address of the first row of the 2D array, which is equivalent to the address of the first element of the first row (arr[0][0]).

    // 3. cout << arr[0][0];: This will print the value at the first element of the first row of the 2D array.

    // Q2. How memory is deallocated in case of dynamically created 3D arrays in c++.

    // int L, B, H;
    // cin >> L >> B >> H;

    // int ***ptr = new int **[L];

    // for (int i = 0; i < L; i++)
    // {
    //     ptr[i] = new int *[B];
    //     for (int j = 0; j < B; j++)
    //     {
    //         ptr[i][j] = new int[H];
    //     }
    // }

    // for (int i = 0; i < L; i++)
    //     for (int j = 0; j < B; j++)
    //         for (int k = 0; k < H; k++)
    //             ptr[i][j][k] = i + j + k;

    // for (int i = 0; i < L; i++)
    //     for (int j = 0; j < B; j++)
    //         for (int k = 0; k < H; k++)
    //             cout << ptr[i][j][k] << " ";

    // for (int i = 0; i < L; i++)
    // {
    //     for (int j = 0; j < B; j++)
    //         delete[] ptr[i][j];
    // }

    // delete[] ptr;

    // Q4. Dynamically create 4D arrays in C++.
    int L, B, H, T;
    cin >> L >> B >> H >> T;

    int ****ptr = new int ***[T];

    for (int i = 0; i < T; i++)
    {
        ptr[i] = new int **[L];
        for (int j = 0; j < L; j++)
        {
            ptr[i][j] = new int *[B];
            for (int k = 0; k < B; k++)
            {
                ptr[i][j][k] = new int[H];
            }
        }
    }
}