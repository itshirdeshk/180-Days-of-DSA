#include <iostream>
#include <vector>
using namespace std;

// Q1. Defanging an IP Address.
string defangIPaddr(string address)
{
    string ans;
    int index = 0;

    while (index < address.size())
    {
        if (address[index] == '.')
            ans += "[.]";
        else
            ans += address[index];
        index++;
    }
    return ans;
}

// Q2. Check if string is rotated by two places.
void rotateCw(string &s)
{
    char c = s[s.size() - 1];
    int index = s.size() - 2;

    while (index >= 0)
    {
        s[index + 1] = s[index];
        index--;
    }
    s[0] = c;
}

void rotateAcw(string &s)
{
    char c = s[0];
    int index = 1;

    while (index < s.size())
    {
        s[index - 1] = s[index];
        index++;
    }
    s[s.size() - 1] = c;
}

bool isRotated(string str1, string str2)
{
    // Your code here
    if (str1.size() != str2.size())
        return 0;

    string cw, acw;

    cw = str1;

    rotateCw(cw);
    rotateCw(cw);

    if (cw == str2)
        return 1;

    acw = str1;
    rotateAcw(acw);
    rotateAcw(acw);

    if (acw == str2)
        return 1;

    return 0;
}

// Q3. Check if the Sentence Is Pangram.
bool checkIfPangram(string sentence)
{
    if (sentence.size() < 26)
        return 0;

    vector<bool> alpha(26, 0);
    for (int i = 0; i < sentence.size(); i++)
    {
        alpha[sentence[i] - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0)
            return 0;
    }

    return 1;
}

// Q4. Sort a String.
string sort(string s)
{
    // complete the function here
    vector<int> alpha(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'a']++;
    }
    string ans;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        while (alpha[i])
        {
            ans += c;
            alpha[i]--;
        }
    }
    return ans;
}

int main() {}