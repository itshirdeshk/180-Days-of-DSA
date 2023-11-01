#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Left Rotate Matrix K times.
vector<vector<int>> rotateMatrix(int N, int M, int K, vector<vector<int>> Mat)
{
    // code here
    for (int i = 0; i < N; i++)
    {
        int k = K % M;

        // Reverse the first k elements
        reverse(Mat[i].begin(), Mat[i].begin() + k);

        // Reverse the remaining n-k elements
        reverse(Mat[i].begin() + k, Mat[i].begin() + M);

        // Reverse the entire Matay
        reverse(Mat[i].begin(), Mat[i].end());
    }
    return Mat;
}

int main() {}