#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Minimum characters to be added at front to make string palindrome.
int minChar(string str)
{
    // Write your code here
    string rev = str;
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

    return size - lps[n - 1];
}

// Q2. Cicular Pattern Matching

void lpsFind(vector<int> &lps, string s)
{
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
}

int KMP_Match(string haystack, string needle)
{
    vector<int> lps(needle.size(), 0);
    lpsFind(lps, needle);

    int first = 0, second = 0;

    while (first < haystack.size() && second < needle.size())
    {
        if (haystack[first] == needle[second])
            first++, second++;
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
    }

    if (second == needle.size())
        return 1;
    return 0;
}

int circularPatternMatching(string a, string b)
{
    if (a == b)
        return 1;

    a += a;

    return KMP_Match(a, b);
}

// Q3. Repeated String Match.
void lpsFind(vector<int> &lps, string s)
{
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
}

int KMP_Match(string haystack, string needle)
{
    vector<int> lps(needle.size(), 0);
    lpsFind(lps, needle);

    int first = 0, second = 0;

    while (first < haystack.size() && second < needle.size())
    {
        if (haystack[first] == needle[second])
            first++, second++;
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
    }

    if (second == needle.size())
        return 1;
    return 0;
}

int repeatedStringMatch(string a, string b)
{
    if (a == b)
        return 1;

    int repeat = 1;
    string temp = a;

    while (temp.size() < b.size())
    {
        temp += a;
        repeat++;
    }

    // KMP Pattern Search
    if (KMP_Match(temp, b) == 1)
        return repeat;

    // Repeat one more time then again KMP Search
    if (KMP_Match(temp + a, b) == 1)
        return repeat + 1;

    return -1;
}

int main() {}