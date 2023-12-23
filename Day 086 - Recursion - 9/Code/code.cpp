#include <iostream>
#include <vector>
using namespace std;

// Q1. Subsequence.
void subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp)

{
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[index]);
    subseq(arr, index + 1, n, ans, temp);
    temp.pop_back();
    subseq(arr, index + 1, n, ans, temp);
}

// Q2. Generate Parentheses.
void parenthesis(int n, int left, int right, vector<string> &ans, string &temp){
        if(left + right == 2 * n){
            ans.push_back(temp);
            return;
        }

        if(left < n){
            temp.push_back('(');
            parenthesis(n, left + 1, right, ans, temp);
            temp.pop_back();
        }

        if(right < left){
            temp.push_back(')');
            parenthesis(n, left, right + 1, ans, temp);
            temp.pop_back();
        }
    }

int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;

    subseq(arr, 0, 3, ans, temp);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }


}