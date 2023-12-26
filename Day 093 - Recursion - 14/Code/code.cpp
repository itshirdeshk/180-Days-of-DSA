#include <iostream>
using namespace std;

// Q1. Tower of Hanoi.
void tohcal(int N, int source, int helper, int des)
{
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << source << " to rod " << des << endl;
        return;
    }

    tohcal(N - 1, source, des, helper);
    cout << "move disk " << N << " from rod " << source << " to rod " << des << endl;
    tohcal(N - 1, helper, source, des);
}

int main() {}