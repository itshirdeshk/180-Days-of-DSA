#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1. The Celebrity Problem.
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
        st.push(i);

    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();

        if (M[first][second] && !M[second][first])
            st.push(second);
        if (!M[first][second] && M[second][first])
            st.push(first);
    }

    if (st.empty())
        return -1;

    int num = st.top(), row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        row += M[num][i];
        col += M[i][num];
    }

    return row == 0 && col == n - 1 ? num : -1;
}





int main() {}