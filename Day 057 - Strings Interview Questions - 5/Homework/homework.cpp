#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Smallest window containing 0, 1 and 2.
int smallestSubstring(string S)
{
    // Code here
    int n = S.size();
    // Initialize the answer variable to a value greater than the maximum possible length
    int ans = n + 1;
    // Initialize two pointers i and j for traversing the string
    int i = 0;
    int j = 0;
    // Create an array to store the count of each character (assuming characters are '0', '1', and '2')
    int count[3] = {0, 0, 0};
    // Loop through the string
    while (i < n)
    {
        // Increment the count of the current character at position i
        count[S[i] - '0']++;
        i++;
        // Check if there are duplicates of any character in the current substring
        while (j < i && count[S[j] - '0'] > 1)
        {
            // If there are duplicates, decrement the count of the character at position j and move the pointer j
            count[S[j] - '0']--;
            j++;
        }
        // Check if the current substring contains at least one occurrence of each character ('0', '1', and '2')
        if (count[0] > 0 && count[1] > 0 && count[2] > 0)
        {
            // Update the answer with the minimum length of the substring containing all characters
            ans = min(ans, i - j);
        }
    }
    // If the answer is still greater than the maximum possible length, no valid substring was found
    if (ans == n + 1)
    {
        return -1;
    }
    else
    {
        // Return the minimum length of substring containing all characters
        return ans;
    }
}

// Q2. Longest K unique characters substring.
int longestKSubstr(string s, int k)
{
    // Initialize pointers, answer variable, and character count
    int i = 0, j = 0, ans = 0;
    int size = 0;
    vector<int> mp(26, 0); // Array to store the count of each character
    int n = s.length();    // Length of the input string
    // Sliding window approach
    while (i < n && j < n)
    {
        // If the number of distinct characters exceeds k
        if (size > k)
        {
            mp[s[i] - 'a']--; // Decrease the count of the character at the beginning of the window
            if (mp[s[i] - 'a'] == 0)
            {
                size--; // If count becomes 0, reduce the size of distinct characters
            }
            i++; // Move the window forward
        }
        else
        {
            // If the number of distinct characters is less than or equal to k
            if (mp[s[j] - 'a'] == 0)
            {
                size++; // Increase the size of distinct characters
            }
            mp[s[j] - 'a']++; // Increase the count of the character at the end of the window
            j++;              // Move the window forward
            // If the size of distinct characters becomes equal to k, update the answer
            if (size == k)
            {
                ans = max(ans, j - i);
            }
        }
    }
    // If no substring with k distinct characters is found, return -1
    if (ans == 0)
    {
        return -1;
    }
    else
    {
        return ans; // Return the length of the longest substring with k distinct characters
    }
}

int main() {}