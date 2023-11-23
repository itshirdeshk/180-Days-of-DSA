#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Minimum Appends for Palindrome!
int solve(string A)
{
    string rev = A;
    reverse(rev.begin(), rev.end());
    rev += '$';
    rev += A;

    vector<int> lps(rev.size(), 0);
    int pre = 0, suf = 1;

    while (suf < rev.size())
    {
        if (rev[pre] == rev[suf])
            lps[suf++] = (pre++) + 1;
        else
        {
            if (pre == 0)
                suf++;
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
    return A.size() - lps[rev.size() - 1];
}

// Q2. Shortest Palindrome.
string shortestPalindrome(string str)
{
    string rev = str;
    string org = str;
    reverse(rev.begin(), rev.end());
    int size = str.size();
    str += '$';
    str += rev;

    // Longest Prefix Suffix
    int n = str.size();
    vector<int> lps(n, 0);

    int pre = 0, suf = 1;
    while (suf < str.size())
    {
        if (str[pre] == str[suf])
            lps[suf++] = (pre++) + 1;
        else
        {
            if (pre == 0)
                suf++;
            else
                pre = lps[pre - 1];
        }
    }
    string ans;
    for (int i = size - 1; i >= lps[n - 1]; i--)
    {
        ans += org[i];
    }
    return ans += org;
}

int main() {}