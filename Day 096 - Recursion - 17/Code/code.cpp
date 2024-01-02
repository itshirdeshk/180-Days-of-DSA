#include<iostream>
#include<vector>
using namespace std;

// Q1. Print N-bit binary numbers having more 1s than 0s.
void find(int N, vector<string> &ans, string &temp, int zero, int one){
        if(temp.size() == N){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('1');
        find(N, ans, temp, zero, one + 1);
        temp.pop_back();
        
        if(zero < one){
            temp.push_back('0');
            find(N, ans, temp, zero + 1, one);
            temp.pop_back();
        }
    }


int main() {}