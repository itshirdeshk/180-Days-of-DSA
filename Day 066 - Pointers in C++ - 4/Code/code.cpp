#include<iostream>
using namespace std;

void fun(int *p){
    *p = *p + 5;
}

int main () {
    int n = 10;
    int *p = &n;
    int **p2 = &p;
    int ***p3 = &p2;

    // cout<<p<<endl;
    // cout<<p2<<endl;
    // cout<<p3<<endl;

    // // Value Modification
    // *p = *p + 5;
    // **p2 = **p2 + 5;
    // ***p3 = ***p3 + 5;
    // cout<<n<<endl;

    fun(p);
    cout<<n<<endl; 


}