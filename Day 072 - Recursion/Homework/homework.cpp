#include <iostream>
using namespace std;

void CoderArmy(int n)
{
    if (n == 0)
        return;
    cout<<"Coder Army\n";
    CoderArmy(n - 1);
}

void printOdd(int n){
    if(n == 1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    printOdd(n - 2);
}

void Print(int i, int n){
    if(i == n){
        cout<<i<<endl;
        return;
    }
    cout<<i<<endl;
    Print(i + 1, n);
}

int main()
{
    // Q1. Print “Coder Army” 10 times using recursion.
    int n = 10;
    CoderArmy(10);

    // Q2. Print all odd number from n to 1 using recursion.
    int n = 9;
    printOdd(n);

    // Q3. Print all numbers from 1 to n using recursion. 
    int n = 10;
    Print(1, n);
}