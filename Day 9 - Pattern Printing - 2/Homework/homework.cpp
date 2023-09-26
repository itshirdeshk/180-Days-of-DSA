#include<iostream>
using namespace std;

int main() {
    // First Pattern
    for(int row = 1; row <= 5; row++) {
        for(int col = 1; col <= row; col++) {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    // Second Pattern
    for(int row = 1; row <= 5; row++) {
        
        for(int col = 1; col <= row; col++) {
            char alpha = 'A' + (col - 1);
            cout<<alpha<<" ";
        }
        cout<<endl;
    }

    // Third Pattern
    for(int row = 10; row <= 15; row++) {
        for(int col = 10; col <= row; col++) {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    // Fourth Pattern
    for(int row = 1; row <= 4; row++) {
        for(int col = 4; col >= row; col--) {
            char alpha = 'A' + (4 - col);
            cout<<alpha<<" ";
        }
        cout<<endl;
    }
}