#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // creating vector
    vector<int> v;
    vector<int> v1(5, 1);
    vector<int> v2 = {1, 2, 3, 4, 5};

    // size and capacity
    cout << "Size of v: " << v.size() << endl;
    cout << "Capacity of v: " << v.capacity() << endl;

    // inserting element
    v.push_back(2);
    cout << "Size of v: " << v.size() << endl;
    cout << "Capacity of v: " << v.capacity() << endl;

    v.push_back(3);
    v.push_back(4);
    cout << "Size of v: " << v.size() << endl;
    cout << "Capacity of v: " << v.capacity() << endl;

    // updating value
    v[1] = 5;

    cout << "Size of v2: " << v2.size() << endl;
    cout << "Capacity of v2: " << v2.capacity() << endl;

    // deleting element
    v.pop_back();
    v.erase(v.begin() + 1);

    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // printing elements
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;

    // inserting element at a particular index
    v.insert(v.begin() + 1, 10);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }

    cout<<endl;

    cout << "Size of v1: " << v1.size() << endl;
    cout << "Capacity of v1: " << v1.capacity() << endl;

    v1.clear();

    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }

    cout << "Size of v1: " << v1.size() << endl;
    cout << "Capacity of v1: " << v1.capacity() << endl;

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(23);
    arr.push_back(24);
    arr.push_back(25);

    cout << arr.front() << endl;
    cout << arr.back() << endl;

    vector<int> a;

    // copy the values of 1 vector to another
    a = arr;

    // Another way of printing elements
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }

    cout<<endl;

    for (auto i : arr)
    {
        cout << i << " ";
    }

    vector<int> ans;
    ans.push_back(5);
    ans.push_back(4);
    ans.push_back(3);
    ans.push_back(2);
    ans.push_back(1);

    // sort in increasing order
    sort(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;

    // sort in decreasing order
    sort(ans.begin(), ans.end(), greater<int>());

    // Another way 
    sort(ans.rbegin(), ans.rend());

    for (auto it : ans)
    {
        cout << it << " ";
    }

    // search by using binary search
    cout<<binary_search(ans.begin(), ans.end(), 1)<<endl;

    cout<<find(ans.begin(), ans.end(), 1) - ans.begin()<<endl;
}