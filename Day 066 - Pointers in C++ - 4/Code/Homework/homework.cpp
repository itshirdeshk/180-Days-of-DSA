#include <iostream>
using namespace std;

void modifyString(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 'a' + 'A';
        }
        str++;
    }
}

void concatenateAndPrint(char *str1, const char *str2)
{
    while (*str1)
    {
        str1++;
    }

    while ((*str1 = *str2))
    {
        str1++, str2++;
    }
}

void reverseString(char *str)
{
    char *end = str;
    while (*end)
    {
        end++;
    }
    end--;

    while (str < end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++, end--;
    }
}

void updateValues(int *a, int *b)
{
    *a += *b;
    *b = abs(*a - 2 * (*b));
}

void countVowelsAndConsonants(const char *str, int &vowels, int &consonants)
{
    vowels = consonants = 0;

    while (*str)
    {
        char ch = tolower(*str);
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        str++;
    }
}

void foo(int *i, int *j)
{
    *i = *i + *j;
    *j = *i - *j;
    *i = *i - *j;
}

int main()
{
    // Q1.
    char myString[] = "hello World";
    modifyString(myString);
    cout << myString;
    return 0;

    // Q2.
    char first[] = "Good";
    const char second[] = "Morning";
    concatenateAndPrint(first, second);
    cout << first;
    return 0;

    // Q3.
    char myString[] = "Programming";
    reverseString(myString);
    cout << myString;
    return 0;

    // Q4.
    int x = 5, y = 3;
    updateValues(&x, &y);
    cout << x << " " << y;
    return 0;

    // Q5.
    const char *text = "Hello, World!";
    int numVowels, numConsonants;
    countVowelsAndConsonants(text, numVowels, numConsonants);
    cout << "Vowels: " << numVowels << ", Consonants: " << numConsonants;
    return 0;

    // Q6.
    int a = 4, b = 5;
    foo(&a, &b);
    cout << a << " " << b;
}