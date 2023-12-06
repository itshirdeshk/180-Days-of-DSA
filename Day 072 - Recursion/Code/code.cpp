#include<iostream>
using namespace std;

void wish(int n){
    if(n == 0){
        cout<<"Happy Birthday";
        return;
    }
    cout<<n<<" days left for Birthday. \n";
    wish(n - 1);
}

void Print(int n) {
    if(n == 1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    Print(n - 1);
}

void printEven(int n) {
    if(n == 2){
        cout<<2<<endl;
        return;
    }
    cout<<n<<" ";
    printEven(n - 2);
}

int main() {
    int n = 5;
    // Iterative Approach
    for(int i = n; i > 0; i--) {
        cout<<i<<" days left for Birthday. \n";
    }

    cout<<"Happy Birthday";

    // Recursive Approach
    wish(n);

    // Print n to 1
    int n = 5;
    // Iterative Approach
    for(int i = n; i > 0; i--) {
        cout<<i<<" ";
    }

    // Recursive Approach
    Print(n);

    // Print n to 1 (only even no)
    int n = 10;
    printEven(n);
}