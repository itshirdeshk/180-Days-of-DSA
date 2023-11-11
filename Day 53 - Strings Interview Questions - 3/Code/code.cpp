#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Q1. Sort Vowels in a String.
string sortVowels(string s)
{
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            lower[s[i] - 'a']++;
            s[i] = '#';
        }
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            upper[s[i] - 'A']++;
            s[i] = '#';
        }
    }

    string ans;
    for (int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        while (upper[i])
        {
            ans += c;
            upper[i]--;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (lower[i])
        {
            ans += c;
            lower[i]--;
        }
    }

    int first = 0, second = 0;
    while (second < ans.size())
    {
        if (s[first] == '#')
        {
            s[first] = ans[second];
            second++;
        }
        first++;
    }
    return s;
}

// Q2. Add Strings.
string add(string num1, string num2)
{
    string ans;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int sum, carry = 0;
    while (index2 >= 0)
    {
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--, index2--;
    }

    while (index1 >= 0)
    {
        sum = (num1[index1] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        index1--;
    }

    if (carry)
        ans += '1';

    reverse(ans.begin(), ans.end());
    return ans;
}

string addStrings(string num1, string num2)
{
    if (num1.size() < num2.size())
        return add(num2, num1);
    else
        return add(num1, num2);
}

int main() {}