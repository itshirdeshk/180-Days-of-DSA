#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Longest Substring Without Repeating Characters.
int lengthOfLongestSubstring(string s)
{
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;

    while (second < s.size())
    {
        while (count[s[second]])
        {
            count[s[first]] = 0;
            first++;
        }
        count[s[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}

// Q2. Smallest distinct window.
int findSubString(string str)
{
    // Your code goes here
    vector<int> count(256, 0);
    int first = 0, second = 0, len = str.size(), diff = 0;

    // Calculate all the unique chars
    while (first < str.size())
    {
        if (count[str[first]] == 0)
        {
            diff++;
        }
        count[str[first]]++;
        first++;
    }

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    first = 0;

    while (second < str.size())
    {
        while (diff && second < str.size())
        {
            if (count[str[second]] == 0)
                diff--;

            count[str[second]]++;
            second++;
        }

        len = min(len, second - first);

        while (diff != 1)
        {
            len = min(len, second - first);
            count[str[first]]--;

            if (count[str[first]] == 0)
                diff++;

            first++;
        }
    }
    return len;
}

int main() {}