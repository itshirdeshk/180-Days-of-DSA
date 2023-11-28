#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

void printCol(int arr[][4], int row, int col)
{
    // Column Wise
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
            cout << arr[i][j] << " ";
    }
}

void printRowMax(int arr[][4], int row, int col)
{
    int index = -1, sum = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int total = 0;
        for (int j = 0; j < col; j++)
        {
            total += arr[i][j];
        }

        if (sum < total)
        {
            sum = total;
            index = i;
        }
    }

    cout << index;
}

void printSumDig(int matrix[][3], int row, int col)
{
    int first = 0, second = 0;
    for (int i = 0; i < row; i++)
        first += matrix[i][i];

    int i = 0, j = col - 1;
    while (j >= 0)
    {
        second += matrix[i][j];
        i++;
        j--;
    }

    cout << first + second << endl;
}

void reverseRow(int matrix[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int start = 0, end = col - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }
}

int main()
{
    // creating a 2D Array
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int ans[3][4];

    // Printing the Array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
    }

    cout<<endl;

    // Print all the column wise, using function call.
    printCol(arr, 3, 4);

    cout<<endl;

    // Find an element in our array.
    int x = 7;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            if(arr[i][j] == x) {
                cout<<"Yes";
                return 0;
            }
    }

    cout<<"No"<<endl;

    // Adding 2 Matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            ans[i][j] = arr[i][j] + arr1[i][j];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << ans[i][j] << " ";
    }

    printRowMax(arr, 3, 4);

    // Printing diagonal sum
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printSumDig(matrix, 3, 3);

    reverseRow(matrix, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
    }
}