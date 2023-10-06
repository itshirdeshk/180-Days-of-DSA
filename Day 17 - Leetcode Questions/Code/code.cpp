#include<iostream>
#include<limits.h>
using namespace std;

// Q1. Add Digits
class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
        int ans = 0;
            while(num != 0) {
                int rem = num % 10;
                num /= 10;
                ans = ans + rem;
            }
            num = ans;
        }
        return num;
    }
};

// Q2. Leap Year
class Solution{
public:
    int isLeap(int N){
        //code here
        if(N % 400 == 0) {
            return 1;
        } else if(N % 4 == 0 && N % 100 != 0) {
            return 1;
        } else {
            return 0;
        }
    }
};

// Q3. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        int ans = 0, rem;
        while(x != 0) {
            rem = x % 10;
            x /= 10;

            if(ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;
            ans = ans * 10 + rem;
        }

        return ans;
    }
};

// Q4. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n < 1)
            return 0;
        while(n != 1) {
            if(n % 2 == 1)
                return 0;
            n /= 2;
        }
        return 1;
    }
};

// Q5. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        long i;
        for(i = 0; i * i <= INT_MAX; i++){
            if(i * i == x) {
                return i;
            }
            else if(i * i > x){
                return i - 1;
            }
        }
        return (int)i - 1;
    }
};


// Q6. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        
        int num = x, ans = 0, rem;
        while(num != 0) {
            rem = num % 10;
            num /= 10;
            if(ans > INT_MAX / 10){
                return 0;
            }
            ans = ans * 10 + rem;
        }

        if(ans == x)
            return 1;
        return 0;
    }
};

// Q7. Complement of Base 10 Integer
class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(i * i <= x){
            if(i * i >= INT_MAX) {
                return i - 1;
                break;
            }
            i++;
        }
        return i - 1;
    }
};