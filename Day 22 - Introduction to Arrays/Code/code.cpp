#include<iostream>
using namespace std;

int main() {

    int a = 5;
    cout<<sizeof(a)<<" "; 

    // Always give a value to the size not any variable. 
    int arr1[5] = {0};
    int arr[5] = {1, 2, 3, 4, 5};

    // To find the number of elements in the array
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;

    for(int i = 0; i < 5; i++) {
        cout<<arr[i]<<" ";
    }

    // To find min element of the array
    int ans = arr[0];
    for(int i = 0; i < 5; i++) {
        if(arr[i] < ans)
            ans = arr[i];
    }

    cout<<ans<<endl;

    // To find max element of the array
    int ans1 = arr[0];
    for(int i = 0; i < 5; i++) {
        if(arr[i] > ans1)
            ans1 = arr[i];
    }

    cout<<ans1<<endl;
}