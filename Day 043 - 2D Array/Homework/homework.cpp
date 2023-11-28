#include <iostream>
#include <limits.h>
using namespace std;

// Q1. Print sum of each column in 2D array.
void colSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

// Q2. Given 2 matrices A and B, Print A-B.
void diff(int arr1[][3], int arr2[][3], int row, int col)
{
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

// Q3. Given a matrix of size n*n, Print sum of diagonal element.
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

    cout << first + second - matrix[row / 2][row / 2] << endl;
}

// Q5. Largest Element: Find and print the largest element in the 2D array.
void maxElement(int arr[][3], int row, int col)
{
    int max = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    cout << max;
}

// Q6. Smallest Element: Find and print the smallest element in the 2D arrays.
void minElement(int arr[][3], int row, int col)
{
    int min = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    cout << min;
}

int main()
{
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printSumDig(matrix, 3, 3);
}