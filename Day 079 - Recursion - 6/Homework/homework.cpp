#include <iostream>
using namespace std;

// Q1. Palindrome String.
bool checkPal(string str, int start, int end)
{
    if (start >= end)
        return 1;

    if (str[start] != str[end])
        return 0;
    else
        return checkPal(str, start + 1, end - 1);
}

// Q2. Lower case to upper case.
void lowerToUpper(string &str, int index)
{
    if (index == -1)
        return;

    str[index] = 'A' + str[index] - 'a';
    lowerToUpper(str, index - 1);
}

// Q3. Convert String to LowerCase.
void upperToLower(string &str, int index)
{
    if (index == -1)
        return;

    if (str[index] < 'a')
    {
        str[index] = 'a' + str[index] - 'A';
    }
    upperToLower(str, index - 1);
}

// Q4. Reverse a String.
void rev(string &str, int start, int end)
{
    if (start >= end)
        return;

    char c = str[start];
    str[start] = str[end];
    str[end] = c;

    rev(str, start + 1, end - 1);
}

// Q5. Given a String, count the number of consonants in it.
int count(string str, int index)
{
    if (index == -1)
        return 0;
    if (str[index] != 'a' || str[index] != 'e' || str[index] != 'i' || str[index] != 'o' || str[index] != 'u')
        return 1 + count(str, index - 1);

    else
        return count(str, index - 1);
}

int main() {}