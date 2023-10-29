#include<iostream>
#include<vector>
using namespace std;

// Q1. 

// Q2. Remove Duplicates from Sorted Array.
int removeDuplicates(vector<int> &A) {
    int n=A.size();
    int i=0,j=0,ans=0;
    while(i<n){
        while(A[i]==A[i+1] && i<n-1) i++;
        swap(A[i++],A[j++]);
        ans++;
    }
    return ans;
}


int main() {}