#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void display(queue<int> q)
{
    while (q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Q1. Print all numbers in every window of size k.
void printKElements(int arr[], int k, int n)
{
    queue<int> q;
    for (int i = 0; i < k - 1; i++)
        q.push(arr[i]);
    for (int i = k - 1; i < n; i++)
    {
        q.push(arr[i]);
        display(q);
        q.pop();
    }
}

// Q2. First negative integer in every window of size k.
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    queue<long long> q;

    for (int i = 0; i < K - 1; i++)
    {
        if (A[i] < 0)
            q.push(i);
    }

    for (int i = K - 1; i < N; i++)
    {
        if (A[i] < 0)
            q.push(i);
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            if (q.front() <= i - K)
                q.pop();
            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(A[q.front()]);
        }
    }

    return ans;
}

// Q3. First non-repeating character in a stream of characters.
string solve(string A)
{
    string B = "";
    vector<int> repeated(26, 0);
    queue<char> q;

    for (int i = 0; i < A.size(); i++)
    {
        if (repeated[A[i] - 'a'] >= 1)
        {
            repeated[A[i] - 'a']++;
            while (!q.empty() && repeated[q.front() - 'a'] > 1)
                q.pop();
            if (q.empty())
                B += '#';
            else
                B += q.front();
        }
        else
        {
            repeated[A[i] - 'a']++;
            q.push(A[i]);
            while (repeated[q.front() - 'a'] > 1)
                q.pop();
            B += q.front();
        }
    }
    return B;
}

int main() {}