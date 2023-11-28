#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Q4. How to pass a vector to a function. Write a small code for it.
int func(vector<int> arr)
{
    cout << "Pass a vector to a function";
    return 0;
}

int main()
{
    // Q1. How to find the number of Occurance of an element in a vector. You need to use STL here.
    vector<int> ans(5, 1);
    cout << count(ans.begin(), ans.end(), 1) << endl;

    // Q2. How to find maximum and minimum elements from the vector. USE STL here.
    ans.push_back(2);
    ans.push_back(3);

    cout << *max_element(ans.begin(), ans.end()) << endl;
    cout << *min_element(ans.begin(), ans.end()) << endl;

    // Q3. Find Lower bound and Upper Bound of a given element in a sorted vector. USE STL here to find them.
    cout << lower_bound(ans.begin(), ans.end(), 1) - ans.begin() << endl;
    cout << upper_bound(ans.begin(), ans.end(), 1) - ans.begin() - 1 << endl;

    func(ans);
}