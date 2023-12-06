#include<iostream>
using namespace std;

void print(int num, int N){
    if(num == N){
        cout<<num<<endl;
        return;
    }

    cout<<num<<endl;
    print(num + 1, N);
}

void print2(int n){
    if(n == 1){
        cout<<n<<endl;
        return;
    }
    print2(n - 1);
    cout<<n<<endl;
}

void printEven(int n){
    if(n == 2){
        cout<<2<<endl;
        return;
    }

    printEven(n - 2);
    cout<<n<<endl;
}

int main() {
    // Print from 1 to n
    int n = 10;
    print(1, n);
    print2(n);

    // Print even number from 1 to n
    int n = 11;
    if(n % 2 == 1)
        n--;
    printEven(n);
}