#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Roman to Integer.
int num(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else
        return 1000;
}

int romanToInt(string s)
{
    int sum = 0, index = 0;
    while (index < s.size() - 1)
    {
        if (num(s[index]) < num(s[index + 1]))
            sum -= num(s[index]);
        else
            sum += num(s[index]);
        index++;
    }

    sum += num(s[s.size() - 1]);
    return sum;
}

// Q2. Factorials of large numbers.
vector<int> factorial(int N)
{
    // code here
    vector<int> ans(1, 1);

    while (N > 1)
    {
        int carry = 0, res, size = ans.size();
        for (int i = 0; i < size; i++)
        {
            res = ans[i] * N + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        N--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {}