#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    int age;
    string name;

    bool operator<(const Person &other) const
    {
        return age < other.age;
    }
};

int main()
{
    // 1. Pair:
    // pair<string, int> p;

    // Methods of Pair Creation
    // Method 1:
    // p = make_pair("rohit", 30);
    // cout<<p.first<<" "<<p.second<<endl;

    // Method 2:
    // p.first = "Rohit";
    // p.second = 30;
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<string, pair<int, int>> p;

    // Method 1:
    // p.first = "Rohit";
    // p.second.first = 30;
    // p.second.second = 10;

    // Method 2:
    // p = make_pair("Rohit", make_pair(30, 10));

    // 2. List:
    // list<int> l;

    // l.push_back(30);
    // l.push_back(40);
    // l.push_back(50);

    // l.push_front(20);
    // l.push_front(15);

    // // cout<<l.front()<<" "<<l.back()<<endl;

    // for (auto it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // cout << endl;

    // for (auto it = l.rbegin(); it != l.rend(); it++)
    // {
    //     cout << *it << " ";
    // }

    // 3. Set:
    // set<int> s;
    // // set<int, greater<int>> s;

    // s.insert(20);
    // s.insert(30);
    // s.insert(50);
    // s.insert(30);
    // s.insert(40);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // // Searching any element
    // // find() function
    // if (s.find(20) != s.end())
    //     cout << "Present\n";
    // else
    //     cout << "Absent\n";

    // // count() function
    // if (s.count(20))
    //     cout << "Present\n";
    // else
    //     cout << "Absent\n";

    // // Deleting any element
    // s.erase(40);

    // set<Person> s;
    // Person p1, p2;
    // p1.age = 20, p1.name = "Hirdesh";
    // p2.age = 22, p2.name = "Hitesh";

    // s.insert(p1);
    // s.insert(p2);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << (*it).age << " "<< (*it).name<<endl;
    // }

    // Multiset:
    // Duplicate elements will be present.
    // multiset<int>s;
    // s.insert(20);
    // s.insert(20);
    // s.insert(30);
    // s.insert(40);
    // s.insert(30);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // cout<<endl;

    // s.erase(20);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // Unordered set:
    // unordered_set<int>s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
    // s.insert(7);
    // s.insert(6);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // 4. Map:
    // map<int, int> m;

    // m.insert(make_pair(1, 20));
    // m.insert(make_pair(2, 30));
    // m.insert(make_pair(3, 40));
    // m[4] = 50;

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // m.erase(2);

    // Unordered Map:
    unordered_map<int, int> m;
    m.insert(make_pair(1, 20));
    m.insert(make_pair(2, 30));
    m.insert(make_pair(3, 40));

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
