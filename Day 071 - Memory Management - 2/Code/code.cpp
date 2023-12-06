#include <iostream>
using namespace std;

int main()
{
    // int n, m;
    // cin >> n >> m;

    // int **ptr = new int *[n];

    // // Created a 2d array using pointer
    // for (int i = 0; i < n; i++)
    // {
    //     ptr[i] = new int[m];
    // }

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cin >> ptr[i][j];

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << ptr[i][j]<< " ";

    // // Release the memory
    // for(int i = 0; i < n; i++)
    //     delete[] ptr[i];

    // delete[] ptr;

    int L, B, H;
    cin >> L >> B >> H;

    int ***ptr = new int **[L];

    for (int i = 0; i < L; i++)
    {
        ptr[i] = new int *[B];
        for (int j = 0; j < B; j++)
        {
            ptr[i][j] = new int[H];
        }
    }

    for (int i = 0; i < L; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < H; k++)
                ptr[i][j][k] = i + j + k;

    for (int i = 0; i < L; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < H; k++)
                cout << ptr[i][j][k] << " ";

}