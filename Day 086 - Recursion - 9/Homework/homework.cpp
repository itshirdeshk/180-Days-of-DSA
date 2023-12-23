#include <iostream>
#include<vector>
using namespace std;

// Q1. Given an array of size n, print all the sums possible from its subsequence.
void subseqSum(int arr[], int index, int n, vector<int> &ans, vector<int> &temp)

{
    if (index == n)
    {
        int sum = 0;
        for(int i = 0; i < temp.size(); i++)
            sum += temp[i];
        ans.push_back(sum);
        return;
    }
    temp.push_back(arr[index]);
    subseqSum(arr, index + 1, n, ans, temp);
    temp.pop_back();
    subseqSum(arr, index + 1, n, ans, temp);
}

int main() {
    int arr[] = {1, 2, 3};
    vector<int> ans;
    vector<int> temp;

    subseqSum(arr, 0, 3, ans, temp);
    for(int i = 0; i < ans.size(); i++) 
        cout<<ans[i]<<endl;
}