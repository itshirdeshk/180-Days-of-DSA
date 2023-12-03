#include<iostream>
using namespace std;

int main () {
    int *ptr = new int;
    *ptr = 5;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    
    int *p = new int[n];
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        cout<<p[i]<<endl;
    }

    delete ptr;
    delete[] p;
}