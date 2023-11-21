#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Longest Prefix Suffix.
int lps(string s)
{
    // Your code goes here
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;

    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++, suf++;
        }
        else
        {
            if (pre == 0)
                lps[suf++] = 0;
            else
                pre = lps[pre - 1];
        }
    }
    return lps[s.size() - 1];
}

int main() {}